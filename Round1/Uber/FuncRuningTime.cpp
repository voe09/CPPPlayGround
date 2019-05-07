Implement a function return the exclusive running time of a function, given the function name and a list of logs.

List<string> stands for a list of logs. The logs have the following structure:. 鐗涗汉浜戦泦,涓€浜╀笁鍒嗗湴

functionName  StartOrEnd Time
A start 10     
B start 11
B end 12
A end 20


exclusive running time means the total running time of a function minus the total running time of its nested functions. 
for example, the exclusive running time of A = T(A) - T(B)  T stands for the total running time of a fuction.鐣欏璁哄潧-涓€浜�-涓夊垎鍦�
Func A{
    Func B();
}


