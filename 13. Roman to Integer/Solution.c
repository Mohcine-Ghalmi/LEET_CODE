int romanToInt(char * s){
    int i;
    int sum;

    sum = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                i++;
                sum += 3;
            }else if (s[i + 1] == 'X')
            {
                i++;
                sum += 8;
            }
            sum += 1;
        }
        else if (s[i] == 'V')
            sum += 5;
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                i++;
                sum += 30;
            }else if (s[i + 1] == 'C')
            {
                i++;
                sum += 80;
            }
            sum += 10;
        }
        else if (s[i] == 'L')
            sum += 50;
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                i++;
                sum += 300;
            }else if (s[i + 1] == 'M')
            {
                i++;
                sum += 800;
            }
            sum += 100;
        }
        else if (s[i] == 'D')
            sum += 500;
        else if (s[i] == 'M')
            sum += 1000; 
        i++;
    }
    return (sum);
}