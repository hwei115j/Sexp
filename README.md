# SEXP

簡單的S-expression格式化工具
用來格式化簡易編譯器的S-expression輸出

### 用法：

```
make
./style < dome.scm
```

由stdin輸入文字，stdout輸出
使用Scheme只是因為vim會有縮排

大寫開頭的字母為Key\_word，排版規則為key\_word後第一個element不換行，第二個以後換行，並且對齊第一個element左括號

運算式不換行（+ - \* / & |....)

element：(...)、123、abc、ABC、+、-.........
