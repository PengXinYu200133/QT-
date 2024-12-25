package com.example.shujkeshihua

import android.graphics.Color
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.fragment.app.Fragment
import com.github.mikephil.charting.charts.PieChart
import com.github.mikephil.charting.data.PieData
import com.github.mikephil.charting.data.PieDataSet
import com.github.mikephil.charting.data.PieEntry
import com.google.gson.Gson
import com.google.gson.GsonBuilder
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import java.io.OutputStream
import java.net.Socket

class PieChartsFragment : Fragment() {
    private lateinit var yearPieChart: PieChart
    private lateinit var threeMonthsPieChart: PieChart
    private lateinit var oneMonthPieChart: PieChart
    private lateinit var responseTextView: TextView

    private var socket: Socket? = null

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_pie_charts, container, false)

        // 获取控件
        val ipAddressInput = view.findViewById<EditText>(R.id.ipAddressInput)
        val sendButton = view.findViewById<Button>(R.id.sendButton)
        yearPieChart = view.findViewById(R.id.yearPieChart)
        threeMonthsPieChart = view.findViewById(R.id.threeMonthsPieChart)
        oneMonthPieChart = view.findViewById(R.id.oneMonthPieChart)
        responseTextView = view.findViewById(R.id.responseTextView)

        // 启用 TextView 的文本选择功能（支持复制）
        responseTextView.setTextIsSelectable(true)

        // 按钮点击事件
        sendButton.setOnClickListener {
            val ipAddress = ipAddressInput.text.toString().trim()

            if (ipAddress.isEmpty()) {
                Toast.makeText(requireContext(), "请输入有效的 IP 地址", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            // 启动协程，处理网络请求
            CoroutineScope(Dispatchers.IO).launch {
                sendTcpRequest(ipAddress, 1234)
            }
        }

        return view
    }

    /**
     * 发送 TCP 请求并实时解析数据
     */
    private fun sendTcpRequest(ip: String, port: Int) {
        try {
            Log.d("TCP_CLIENT", "正在尝试连接到 $ip:$port")
            socket = Socket(ip, port)
            val outputStream: OutputStream = socket!!.getOutputStream()
            val inputStream = socket!!.getInputStream()

            // 发送请求
            val request = "getdate\r\n"
            Log.d("TCP_REQUEST", "发送请求：$request")
            outputStream.write(request.toByteArray())
            outputStream.flush()

            // 实时解析数据流
            val buffer = ByteArray(1024)
            val responseBuilder = StringBuilder()
            var bytesRead: Int

            while (inputStream.read(buffer).also { bytesRead = it } != -1) {
                val chunk = String(buffer, 0, bytesRead)
                responseBuilder.append(chunk)
                Log.d("TCP_CHUNK", "收到数据块：$chunk")

                // 检查是否拼接完成 JSON 数据
                CoroutineScope(Dispatchers.Main).launch {
                    processJsonChunks(responseBuilder)
                }
            }

            outputStream.close()
            inputStream.close()
        } catch (e: Exception) {
            e.printStackTrace()
            Log.e("TCP_ERROR", "错误：${e.message}")

            CoroutineScope(Dispatchers.Main).launch {
                responseTextView.text = "连接服务器时发生错误：${e.message}"
                Toast.makeText(requireContext(), "连接服务器时发生错误：${e.message}", Toast.LENGTH_SHORT).show()
            }
        }
    }

    /**
     * 处理 JSON 数据块并拼接完整数据
     */
    private fun processJsonChunks(responseBuilder: StringBuilder) {
        try {
            val response = responseBuilder.toString()
            var startIndex = response.indexOf("{")
            var endIndex = response.lastIndexOf("}")

            while (startIndex != -1 && endIndex != -1 && startIndex < endIndex) {
                // 提取完整 JSON 数据
                val rawData = response.substring(startIndex, endIndex + 1).trim()
                Log.d("TCP_RESPONSE", "提取的原始数据：$rawData")

                // 如果数据是字符串模式，先解析为 JSON 对象
                val jsonData = if (rawData.startsWith("\"") && rawData.endsWith("\"")) {
                    // 去掉字符串的引号并解析 JSON 对象
                    rawData.substring(1, rawData.length - 1).replace("\\\"", "\"")
                } else {
                    rawData
                }

                Log.d("TCP_RESPONSE", "解析后的 JSON 数据：$jsonData")

                // 调用解析和更新饼图的方法
                parseAndDisplayData(jsonData)

                // 从响应中移除已处理的数据
                responseBuilder.delete(0, endIndex + 1)

                // 检查是否还有更多 JSON 数据
                startIndex = responseBuilder.indexOf("{")
                endIndex = responseBuilder.lastIndexOf("}")
            }
        } catch (e: Exception) {
            e.printStackTrace()
            Log.e("TCP_RESPONSE_ERROR", "处理数据块时发生错误：${e.message}")
        }
    }

    /**
     * 解析 JSON 数据并更新饼图
     */
    private fun parseAndDisplayData(jsonResponse: String) {
        try {
            Log.d("JSON_RAW_RESPONSE", "服务器返回的原始数据：$jsonResponse")

            // 使用 Gson 解析 JSON
            val gson = GsonBuilder()
                .setLenient() // 宽松模式，允许处理非规范的 JSON
                .create()

            val data = gson.fromJson(jsonResponse, SingleTimeRangeStats::class.java)

            if (data.stats.isNullOrEmpty() || data.time_range.isEmpty()) {
                throw IllegalArgumentException("数据格式无效：缺少 'stats' 或 'time_range' 字段")
            }

            Log.d("PARSE_RESULT", "解析出的数据：time_range=${data.time_range}, stats=${data.stats.size}")

            // 更新饼图数据
            CoroutineScope(Dispatchers.Main).launch {
                when (data.time_range.trim().lowercase()) {
                    "one_month" -> setupPieChart(oneMonthPieChart, data.stats, "最近一个月统计数据")
                    "three_months" -> setupPieChart(threeMonthsPieChart, data.stats, "最近三个月统计数据")
                    "one_year" -> setupPieChart(yearPieChart, data.stats, "最近一年统计数据")
                    else -> {
                        Toast.makeText(requireContext(), "未知的时间范围：${data.time_range}", Toast.LENGTH_SHORT).show()
                        Log.e("JSON_ERROR", "未知的时间范围：${data.time_range}")
                    }
                }
            }
        } catch (e: Exception) {
            e.printStackTrace()
            Log.e("JSON_PARSE_ERROR", "JSON解析失败，原始数据：$jsonResponse")

            CoroutineScope(Dispatchers.Main).launch {
                responseTextView.text = "解析数据时发生错误：${e.message}"
                Toast.makeText(requireContext(), "解析数据时发生错误：${e.message}", Toast.LENGTH_SHORT).show()
            }
        }
    }

    /**
     * 设置饼图数据
     */
    private fun setupPieChart(pieChart: PieChart, data: List<RoomStat>, label: String) {
        if (data.isEmpty()) {
            Toast.makeText(requireContext(), "饼图数据为空：$label", Toast.LENGTH_SHORT).show()
            return
        }

        val entries = data.map { stat -> PieEntry(stat.count.toFloat(), stat.room_type) }

        val colors = mutableListOf<Int>()
        data.forEachIndexed { index, _ ->
            when (index % 8) {
                0 -> colors.add(Color.BLUE)
                1 -> colors.add(Color.RED)
                2 -> colors.add(Color.YELLOW)
                3 -> colors.add(Color.GREEN)
                4 -> colors.add(Color.MAGENTA)
                5 -> colors.add(Color.rgb(255, 165, 0)) // 橙色
                6 -> colors.add(Color.CYAN)
                7 -> colors.add(Color.rgb(255, 182, 193)) // 粉色
            }
        }

        val dataSet = PieDataSet(entries, label).apply {
            setColors(colors)
            valueTextSize = 12f
            valueTextColor = Color.BLACK
        }

        val pieData = PieData(dataSet)
        pieChart.data = pieData

        pieChart.description.isEnabled = false
        pieChart.isDrawHoleEnabled = true
        pieChart.setDrawEntryLabels(true)
        pieChart.setEntryLabelColor(Color.BLACK)
        pieChart.setEntryLabelTextSize(12f)

        pieChart.invalidate() // 强制刷新饼图
    }
}

/**
 * 数据模型
 */
data class SingleTimeRangeStats(
    val stats: List<RoomStat> = emptyList(),
    val time_range: String = ""
)

data class RoomStat(
    val count: Int = 0,
    val room_type: String = ""
)