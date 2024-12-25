package com.example.shujkeshihua

import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentActivity
import androidx.viewpager2.adapter.FragmentStateAdapter

class ViewPagerAdapter(fragmentActivity: FragmentActivity) : FragmentStateAdapter(fragmentActivity) {

    override fun getItemCount(): Int {
        return 2 // 两个页面
    }

    override fun createFragment(position: Int): Fragment {
        return when (position) {
            0 -> PieChartsFragment() // 第一个页面：圆饼图
            1 -> LeaderboardFragment() // 第二个页面：排行榜
            else -> throw IllegalArgumentException("Invalid position")
        }
    }
}