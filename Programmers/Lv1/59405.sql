-- 코드를 입력하세요
SELECT NAME
FROM ANIMAL_INS
WHERE DATETIME in (select min(DATETIME)
                   from ANIMAL_INS)