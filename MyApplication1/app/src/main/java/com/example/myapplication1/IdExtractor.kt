import java.util.regex.Pattern

object IdExtractor {

    private val idCardRegex = "\\b\\d{6}(19|20)?\\d{2}(0[1-9]|1[0-2])(0[1-9]|[12]\\d|3[01])\\d{3}[0-9Xx]\\b".toRegex()
    private val nameRegex = "[\\u4e00-\\u9fa5]{2,4}".toRegex()

    fun extractIdCardAndName(text: String): Pair<String?, String?> {
        val idCard = idCardRegex.find(text)?.value // 提取身份证号
        val name = nameRegex.find(text)?.value    // 提取姓名
        return Pair(name, idCard)
    }
}