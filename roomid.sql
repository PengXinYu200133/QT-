WITH RECURSIVE RoomNumbers AS (
    SELECT 1 AS num -- 起始编号
    UNION ALL
    SELECT num + 1
    FROM RoomNumbers
    WHERE num <= 200 -- 结束编号
)
-- 插入生成的编号到 room 表，格式化为文本形式
INSERT OR IGNORE INTO room (RoomID) -- 使用 OR IGNORE 避免重复插入
SELECT printf('%04d', num) -- 将数字格式化为文本（四位字符串）
FROM RoomNumbers;