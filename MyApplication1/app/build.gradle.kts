plugins {
    id("com.android.application")
    id("org.jetbrains.kotlin.android")
}

android {
    namespace = "com.example.myapplication1"
    compileSdk = 34

    defaultConfig {
        applicationId = "com.example.myapplication1"
        minSdk = 24
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
    kotlinOptions {
        jvmTarget = "1.8"
    }
}

dependencies {

    implementation("androidx.core:core-ktx:1.13.0")
    implementation("androidx.appcompat:appcompat:1.7.0")
    implementation("com.google.android.material:material:1.9.0") // 保持为稳定版
    implementation("androidx.constraintlayout:constraintlayout:2.1.4") // 使用最新稳定版
    implementation("com.squareup.retrofit2:retrofit:2.9.0")
    implementation("com.squareup.okhttp3:okhttp:4.10.0")
    implementation ("com.google.mlkit:text-recognition:16.0.1")

    // To recognize Chinese script
    implementation("com.google.mlkit:text-recognition-chinese:16.0.1")

    // To recognize Devanagari script
    implementation("com.google.mlkit:text-recognition-devanagari:16.0.1")

    // To recognize Japanese script
    implementation("com.google.mlkit:text-recognition-japanese:16.0.1")

    // To recognize Korean script
    implementation("com.google.mlkit:text-recognition-korean:16.0.1")
}