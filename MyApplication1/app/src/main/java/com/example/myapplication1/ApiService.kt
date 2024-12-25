package com.example.myapplication1

import retrofit2.Call
import retrofit2.http.Body
import retrofit2.http.POST

interface ApiService {
    @POST("/upload")
    fun sendIdCardData(@Body data: Map<String, String>): Call<Void>
}