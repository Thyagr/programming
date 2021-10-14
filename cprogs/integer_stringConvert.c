/*
Convert int to string 
easiest - using snprintf
*/

char* integer_string(int num)
{
    int num_copy = num;
    int negative = 0;
    if (num < 0) 
    {
        negative = 1;
        num = -1*num;
        num_copy = num;
    }
    int digits = 0;
    while (num > 0)
    {
        digits++;
        num /= 10;
    }
    char* s = malloc((digits + negative + 1)*sizeof(char));
    
    if (num == 0) return strcat(s, "0"); // special case
    
    int l = 0;
    if (negative) 
    {
        strcat(s, "-");
        l++;
    }
    while (num_copy > 0)
    {
        int d = num_copy % 10;
        char n[2];
        snprintf(n, 2, "%d", d);
        strcat(s, n);
        num_copy /= 10;
    }
    
    int r = strlen(s) - 1;
    while (l < r) // reverse integer
    {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++, r--;
    }
    
    return s;
}

int main()
{
    int n = -0;
    char* str = integer_string(n);
    printf("%s\n", str);
    
    return 0;
}