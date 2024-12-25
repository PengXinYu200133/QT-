package com.example.myapplication1

import android.util.Log
import okhttp3.MediaType.Companion.toMediaTypeOrNull
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.RequestBody.Companion.toRequestBody

object NetworkManager {
    private const val SERVER_URL = "http://192.168.1.100:8080/upload"

    fun sendDataToServer(data: String) {
        val client = OkHttpClient()

        val requestBody = data.toRequestBody("application/json".toMediaTypeOrNull())
        val request = Request.Builder()
            .url(SERVER_URL)
            .post(requestBody)
            .build()

        client.newCall(request).execute().use { response ->
            if (!response.isSuccessful) {
                Log.e("NetworkManager", "Failed to send data: ${response.message}")
            } else {
                Log.i("NetworkManager", "Data sent successfully!")
            }
        }
    }
}