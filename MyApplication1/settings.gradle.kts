pluginManagement {
    repositories {
        google() // 添加 Google 仓库
        mavenCentral() // 添加 MavenCentral 仓库
        gradlePluginPortal() // 添加 Gradle 插件门户

    }
}
dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google() // 添加 Google 仓库
        mavenCentral()
    }
}

rootProject.name = "My Application1"
include(":app")
