package com.example.myapplication1

import android.util.Log
import java.net.InetAddress
import java.net.Socket

class SendDataToESP8266TCP(
    private val ipAddress: String, // ESP8266 的固定 IP 地址
    private val serverPort: Int, // ESP8266 的端口号
    private val data: String // 要发送的数据
) : Thread() {

    override fun run() {
        try {
            // 创建 TCP 连接并发送数据
            Log.d("SendDataToESP8266TCP", "尝试连接到 IP 地址：$ipAddress，端口：$serverPort")
            val socket = Socket(ipAddress, serverPort)

            // 获取输出流并发送数据
            val outputStream = socket.getOutputStream()
            outputStream.write(data.toByteArray())
            outputStream.flush()

            // 关闭连接
            outputStream.close()
            socket.close()

            Log.d("SendDataToESP8266TCP", "成功发送数据到 ESP8266")
        } catch (e: Exception) {
            Log.e("SendDataToESP8266TCP", "发送数据失败：${e.message}")
            e.printStackTrace()
        }
    }

    companion object {
        /**
         * 测试指定 IP 地址是否可达
         */
        fun isIpReachable(ipAddress: String): Boolean {
            return try {
                val inetAddress = InetAddress.getByName(ipAddress)
                inetAddress.isReachable(1000) // 超时时间：1000 毫秒
            } catch (e: Exception) {
                Log.e("SendDataToESP8266TCP", "IP 地址不可达：${e.message}")
                false
            }
        }
    }
}