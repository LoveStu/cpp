template <typename T>
void minmax(T *a, int n, int &iMax, int &iMin)
{
    if (n < 1)
        return;
    if (n == 1)
    {
        iMax = iMin = 0;
        return;
    }
    int s = 1;
    if (n % 2 == 1)
        iMax = iMin = 0;
    else
    {
        if (a[0] > a[1])
        {
            iMax = 0;
            iMin = 1;
        }
        else
        {
            iMax = 1;
            iMin = 0;
        }
        s = 2;
    }
    for (int i = s; i < n; i += 2）
    {
        if (a[i] > a[i + 1])
        {
            iMax = i;
            iMin = i + 1;
        }
        else
        {
            iMax = i + 1;
            iMin = i;
        }
    }
}
