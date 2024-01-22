class Solution {


public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int medianPosition, int start1, int end1, int start2, int end2)
    {
        if(start1>end1)
        {   
            return nums2[start2];
        }
        else if(start2>end2)
        {
            return nums1[start1];
        }

        int half1=static_cast<int> (end1+start1)/2;
        int half2=static_cast<int> (end2+start2)/2;

        int cantNumbers=half1+half2+1;

        if(cantNumbers<medianPosition)
        {
            if(nums1[half1]<nums2[half2])
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, half1+1, end1, start2, end2);
            }
            else if(nums1[half1]>nums2[half2])
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, start1, end1, half2+1, end2);
            }
            else
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, half1+1, end1, half2+1, end2);
            }
        }

        else if(cantNumbers>medianPosition)
        {
            if(nums1[half1]<nums2[half2])
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, start1, end1, start2, half2-1);
            }

            else if(nums1[half1]>nums2[half2])
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, start1, half1-1, start2, end2);
            }
            else
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, start1, half1-1, start2, half2);
            }
        }
        
        else
        {
            if(nums1[half1]<nums2[half2])
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, half1+1, end1, start2, half2);
            }

            else if(nums1[half1]>nums2[half2])
            {
                return findMedianSortedArrays(nums1, nums2, medianPosition, start1, half1, half2+1, end2);
            }
            else
            {
                //return findMedianSortedArrays(nums1, nums2, medianPosition, start1, half1, start2, half2);
                return nums1[half1];
            }

        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    int len1=nums1.size();
    int len2=nums2.size();

    if(len1==0)
    {
        if(len2%2==0)
        {   
            int mitad=static_cast<int> (len2/2);
            double value=(nums2[mitad]+nums2[mitad-1])/2;
            std::cout<<"entro aqui "<<value;
            
            return (nums2[len2/2]+nums2[(len2/2)-1])/2;
        }

        else
        {
            return nums2[len2/2];
        }
    }        

    else if(len2==0)
    {
        if(len1%2==0)
        {
            return (nums1[len1/2]+nums1[len1/2-1])/2;
        }

        else
        {
            return nums1[len1/2];
        }
    }

    else
    {
        int medianposition=static_cast<int> (len1+len2)/2;
        
        if((len1+len2)%2==0)
        {   
            double median1=findMedianSortedArrays(nums1, nums2, medianposition, 0, len1-1, 0, len2-1);
            double median2=findMedianSortedArrays(nums1, nums2, medianposition-1, 0, len1-1, 0, len2-1);

            return (median1+median2)/2;

        }

        else
        {
            return findMedianSortedArrays(nums1, nums2, medianposition, 0, len1-1, 0, len2-1);   
        }
    }
    }
};
