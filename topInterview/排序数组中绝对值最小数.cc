int FindLeastABSofNumber(int *a, int start, int end)  
{  
    int left;  
    int right;  
    int mid;  
    left = start;  
    right = end;  
    while (left < right)  
    {  
        mid = left + (right - left) / 2;  
        if (a[mid] == 0)  
            return a[mid];  
        else if (a[mid]>0)  
        {  
            right = mid;  
        }  
        else  
        {  
            left = mid;  
        }  
        if (right - left == 1)  
        {  
            return abs(a[left]) < abs(a[right]) ? a[left] : a[right];    //  
        }  
    }  
}  
