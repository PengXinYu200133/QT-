package com.example.myapplication1

import android.app.Activity
import android.app.ProgressDialog
import android.content.Intent
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.os.Bundle
import android.provider.MediaStore
import android.widget.Button
import android.widget.EditText
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import java.io.InputStream

class MainActivity : AppCompatActivity() {

    private lateinit var ipEditText: EditText
    private lateinit var portEditText: EditText
    private lateinit var captureButton: Button
    private lateinit var galleryButton: Button
    private lateinit var sendDataButton: Button
    private lateinit var checkConnectionButton: Button
    private lateinit var imageView: ImageView
    private lateinit var nameTextView: TextView
    private lateinit var ocrResultText: TextView
    private lateinit var connectionStatusText: TextView
    private val REQUEST_IMAGE_CAPTURE = 1
    private val REQUEST_IMAGE_PICK = 2

    // 替换为您的 API Key 和 Secret Key
    private val apiKey = "NnZRRQD9regtN1wgc8C41CzS"
    private val secretKey = "24zinGdeOAVsVlJPfFZYAqbQGMF7yUgU"

    // 用于保存识别后的姓名和身份证号
    private var recognizedName: String? = null
    private var recognizedIdNumber: String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // 初始化控件
        ipEditText = findViewById(R.id.ipEditText)
        portEditText = findViewById(R.id.portEditText)
        captureButton = findViewById(R.id.captureButton)
        galleryButton = findViewById(R.id.galleryButton)
        sendDataButton = findViewById(R.id.sendDataButton)
        checkConnectionButton = findViewById(R.id.checkConnectionButton)
        imageView = findViewById(R.id.imageView)
        nameTextView = findViewById(R.id.nameTextView)
        ocrResultText = findViewById(R.id.ocrResultText)
        connectionStatusText = findViewById(R.id.connectionStatusText)

        // 点击按钮打开相机拍照
        captureButton.setOnClickListener {
            val takePictureIntent = Intent(MediaStore.ACTION_IMAGE_CAPTURE)
            if (takePictureIntent.resolveActivity(packageManager) != null) {
                startActivityForResult(takePictureIntent, REQUEST_IMAGE_CAPTURE)
            } else {
                showErrorDialog("无法打开相机，请检查相机权限或设备支持情况。")
            }
        }

        // 点击按钮从相册选择图片
        galleryButton.setOnClickListener {
            val pickPhotoIntent = Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI)
            startActivityForResult(pickPhotoIntent, REQUEST_IMAGE_PICK)
        }

        // 点击“发送数据”按钮发送姓名和身份证号
        sendDataButton.setOnClickListener {
            val ipAddress = ipEditText.text.toString().trim()
            val port = portEditText.text.toString().trim().toIntOrNull()

            if (ipAddress.isEmpty() || port == null) {
                connectionStatusText.text = "请输入有效的 IP 地址和端口号！"
                return@setOnClickListener
            }

            // 检查身份证信息是否为空
            if (!recognizedName.isNullOrEmpty() && !recognizedIdNumber.isNullOrEmpty()) {
                // 校验身份证号格式，确保没有多余的字符
                if (recognizedIdNumber!!.matches(Regex("^\\d{15}|\\d{17}[0-9X]$"))) {
                    val dataToSend = "name=$recognizedName&idNumber=$recognizedIdNumber\r\n"
                    println("发送的数据: $dataToSend") // 调试打印
                    val sendDataThread = SendDataToESP8266TCP(ipAddress, port, dataToSend)
                    sendDataThread.start()
                } else {
                    showErrorDialog("身份证号格式错误，请重新识别！")
                }
            } else {
                nameTextView.text = "请先识别身份证信息！"
            }
        }

        // 点击检查连接按钮，测试与 ESP8266 通信是否成功
        checkConnectionButton.setOnClickListener {
            val ipAddress = ipEditText.text.toString().trim()
            val port = portEditText.text.toString().trim().toIntOrNull()

            if (ipAddress.isEmpty() || port == null) {
                connectionStatusText.text = "请输入有效的 IP 地址和端口号！"
                return@setOnClickListener
            }

            val progressDialog = ProgressDialog(this).apply {
                setMessage("正在检查连接...")
                setCancelable(false)
                show()
            }

            val checkConnectionThread = object : Thread() {
                override fun run() {
                    val isReachable = SendDataToESP8266TCP.isIpReachable(ipAddress)
                    runOnUiThread {
                        progressDialog.dismiss()
                        if (isReachable) {
                            connectionStatusText.text = "ESP8266 的 IP：$ipAddress 可达！"
                        } else {
                            connectionStatusText.text = "无法连接到 ESP8266，IP：$ipAddress"
                        }
                    }
                }
            }
            checkConnectionThread.start()
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        if (requestCode == REQUEST_IMAGE_CAPTURE && resultCode == Activity.RESULT_OK) {
            val extras = data?.extras
            val imageBitmap = extras?.get("data") as? Bitmap

            if (imageBitmap != null) {
                processImage(imageBitmap)
            } else {
                showErrorDialog("未捕获到有效的图像，请重新拍照！")
            }
        } else if (requestCode == REQUEST_IMAGE_PICK && resultCode == Activity.RESULT_OK) {
            val imageUri = data?.data
            if (imageUri != null) {
                val inputStream: InputStream? = contentResolver.openInputStream(imageUri)
                val imageBitmap = BitmapFactory.decodeStream(inputStream)
                if (imageBitmap != null) {
                    processImage(imageBitmap)
                } else {
                    showErrorDialog("未能加载图片，请重新选择！")
                }
            } else {
                showErrorDialog("未选取有效的图片，请重新选择！")
            }
        } else if (resultCode != Activity.RESULT_OK) {
            showErrorDialog("操作已取消，请重新尝试！")
        }
    }

    // 处理图片并调用身份证识别
    private fun processImage(imageBitmap: Bitmap) {
        imageView.setImageBitmap(imageBitmap)

        // 调用身份证识别功能
        IdCardRecognition.recognizeIdCardFromBitmap(imageBitmap, apiKey, secretKey) { name, idNumber ->
            runOnUiThread {
                if (!name.isNullOrEmpty() && !idNumber.isNullOrEmpty()) {
                    // 校验身份证号格式，避免多余字符
                    val validIdNumber = idNumber.trimEnd('0') // 去掉可能多余的末尾 0
                    if (validIdNumber.matches(Regex("^\\d{15}|\\d{17}[0-9X]$"))) {
                        // 识别成功
                        recognizedName = name
                        recognizedIdNumber = validIdNumber

                        nameTextView.text = "姓名：$name"
                        ocrResultText.text = "身份证号：$validIdNumber"
                    } else {
                        recognizedName = null
                        recognizedIdNumber = null
                        nameTextView.text = "姓名：未识别"
                        ocrResultText.text = "身份证号：未识别"
                        showErrorDialog("身份证号格式错误，请重新识别！")
                    }
                } else {
                    // 识别失败
                    recognizedName = null
                    recognizedIdNumber = null

                    nameTextView.text = "姓名：未识别"
                    ocrResultText.text = "身份证号：未识别"
                    showErrorDialog("身份证识别失败，请确保身份证在图片中清晰可见！")
                }
            }
        }
    }

    // 显示错误对话框
    private fun showErrorDialog(message: String) {
        androidx.appcompat.app.AlertDialog.Builder(this)
            .setTitle("错误")
            .setMessage(message)
            .setPositiveButton("确定", null)
            .show()
    }
}