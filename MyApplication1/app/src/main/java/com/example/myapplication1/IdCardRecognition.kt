package com.example.myapplication1

import android.graphics.Bitmap
import android.util.Base64
import okhttp3.*
import org.json.JSONObject
import java.io.ByteArrayOutputStream
import java.io.IOException

object IdCardRecognition {

    // 获取 Access Token
    fun getAccessToken(
        apiKey: String,
        secretKey: String,
        onSuccess: (String) -> Unit,
        onFailure: (Exception) -> Unit
    ) {
        val url =
            "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=$apiKey&client_secret=$secretKey"
        val client = OkHttpClient()

        val request = Request.Builder()
            .url(url)
            .post(RequestBody.create(null, "")) // 空的 POST 请求体
            .build()

        client.newCall(request).enqueue(object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                onFailure(e)
            }

            override fun onResponse(call: Call, response: Response) {
                response.body?.let { body ->
                    val json = JSONObject(body.string())
                    val accessToken = json.getString("access_token")
                    onSuccess(accessToken)
                } ?: onFailure(Exception("获取 Access Token 失败"))
            }
        })
    }

    // 调用身份证识别 API
    fun recognizeIdCard(
        imageBase64: String,
        accessToken: String,
        onSuccess: (String, String) -> Unit, // 修改：返回姓名和身份证号
        onFailure: (Exception) -> Unit
    ) {
        val url = "https://aip.baidubce.com/rest/2.0/ocr/v1/idcard"
        val client = OkHttpClient()

        val requestBody = FormBody.Builder()
            .add("id_card_side", "front") // front 表示身份证正面
            .add("image", imageBase64) // 传入 Base64 编码的身份证图片
            .build()

        val request = Request.Builder()
            .url("$url?access_token=$accessToken")
            .post(requestBody)
            .addHeader("Content-Type", "application/x-www-form-urlencoded")
            .build()

        client.newCall(request).enqueue(object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                onFailure(e)
            }

            override fun onResponse(call: Call, response: Response) {
                response.body?.let { body ->
                    val json = JSONObject(body.string())
                    val wordsResult = json.getJSONObject("words_result")
                    val name = wordsResult.getJSONObject("姓名").getString("words") // 提取姓名
                    val idNumber = wordsResult.getJSONObject("公民身份号码").getString("words") // 提取身份证号码
                    onSuccess(name, idNumber) // 返回姓名和身份证号
                } ?: onFailure(Exception("身份证识别失败"))
            }
        })
    }

    // 将图片转换为 Base64
    fun bitmapToBase64(bitmap: Bitmap): String {
        val outputStream = ByteArrayOutputStream()
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, outputStream)
        return Base64.encodeToString(outputStream.toByteArray(), Base64.DEFAULT)
    }

    // 识别身份证功能
    fun recognizeIdCardFromBitmap(
        bitmap: Bitmap,
        apiKey: String,
        secretKey: String,
        onResult: (String, String) -> Unit // 修改：返回姓名和身份证号
    ) {
        // 获取 Access Token
        getAccessToken(apiKey, secretKey, { accessToken ->
            // 将图片转换为 Base64
            val imageBase64 = bitmapToBase64(bitmap)

            // 调用身份证识别 API
            recognizeIdCard(imageBase64, accessToken, { name, idNumber ->
                onResult(name, idNumber) // 返回姓名和身份证号
            }, { error ->
                onResult("识别失败", "错误：${error.message}")
            })
        }, { error ->
            onResult("获取 Access Token 失败", "错误：${error.message}")
        })
    }
}