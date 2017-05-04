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
            if (a[i] > a[iMax])
                iMax = i;
            if (a[i + 1] < a[iMin])
                iMin = i + 1;
        }
        else
        {
            if (a[i + 1] > a[iMax])
                iMax = i + 1;
            if (a[i] < a[iMin])
                iMin = i;
        }
    }
}
int findMid(int *a, int beg, int end, int mid)
{
	int leftSum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= 0; --i)
	{
		sum += a[i];
		leftSum = max(sum, leftSum);
	}
	int rightSum = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= end; ++i)
	{
		sum += a[i];
		rightSum = max(sum, rightSum);
	}
	return leftSum + rightSum;
}

int findMax(int *a, int beg, int end)
{
	if (beg == end)
		return a[beg];
	int mid = (beg + end) / 2;
	int leftMax = findMax(a, beg, mid);
	int rightMax = findMax(a, mid + 1, end);
	int crossMax = findMid(a, beg, end, mid);
	return max(leftMax, max(rightMax, crossMax));
}

void findMinMax(int *a, int beg, int end, int &maxItem, int &minItem)
{
	if (beg == end)
	{
		maxItem = minItem = a[beg];
		return;
	}
	if (beg == end - 1)
	{
		maxItem = max(a[beg], a[end]);
		minItem = min(a[beg], a[end]);
		return;
	}
	int mid = (beg + end) / 2;
	int lmax, lmin;
	findMinMax(a, beg, mid, lmax, lmin);

	int rmax, rmin;
	findMinMax(a, mid + 1, end, rmax, rmin);

	maxItem = max(lmax, rmax);
	minItem = min(lmin, rmin);
}

void findMinMax(int *a, int n, int &maxItem, int &minItem)
{
	if (n == 1)
	{
		maxItem = minItem = a[0];
		return;
	}
	if (n == 1)
	{
		maxItem = max(a[0], a[1]);
		minItem = min(a[0], a[1]);
		return;
	}
	int start = 1;
	if (n % 2 == 1)
	{
		maxItem = minItem = a[0];
	}
	else
	{
		maxItem = max(a[0], a[1]);
		minItem = min(a[0], a[1]);
		start += 1;
	}
	for (int i = start; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			maxItem = max(maxItem, a[i]);
			minItem = min(minItem, a[i + 1]);
		}
		else
		{
			maxItem = max(maxItem, a[i + 1]);
			minItem = min(minItem, a[i]);
		}
		
	}
}
