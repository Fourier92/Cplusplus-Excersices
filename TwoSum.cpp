// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class NumberWithIndex;

class NumberWithIndex{

    public:
         int value;
         int index;

    public:
        NumberWithIndex( int v, int i)
         {
          value=v;
          index=i;
         }
};

class MergeSort{
    
    public:
        vector<NumberWithIndex> Merge(vector<NumberWithIndex> nums1, vector<NumberWithIndex> nums2)
        {
            int ind1=0;
            int ind2=0;
            vector<NumberWithIndex> nums3;
            while(ind1< nums1.size() && ind2< nums2.size())
            {
                if(nums1[ind1].value<=nums2[ind2].value)
                {
                    nums3.push_back(nums1[ind1]);
                    ind1++;
                }
                else
                {
                    nums3.push_back(nums2[ind2]);
                    ind2++;
                }
            }
            
            if(ind1==nums1.size())
            {
                nums3.insert(nums3.end(), nums2.begin()+ind2, nums2.end());
            }
            
            else 
            {
                nums3.insert(nums3.end(), nums1.begin()+ind1, nums1.end());  
            }
            
            return nums3;
        }
        
    public:
        vector<NumberWithIndex> Sort(vector<NumberWithIndex> nums)
        {
            return Sort(nums,0,nums.size()-1);
        }
    public:    
        vector<NumberWithIndex> Sort(vector<NumberWithIndex> nums, int start, int end)
        {
            if((end-start)==0)
            {
                return vector<NumberWithIndex> ({nums[start]});
            }
            
            int half= static_cast<int>(start+(end-start)/2);
            
            vector<NumberWithIndex> nums1= Sort(nums,start,half);
            vector<NumberWithIndex> nums2= Sort(nums,half+1,end);
            
            return Merge(nums1, nums2);
            
            
        }
        
};

    
class Bisection{
    
    public:
        vector<int> FindNumber(vector<NumberWithIndex> nums, int target, int start, int end)
        {
            int half=static_cast<int> (start+end)/2;
            if((end-start)==0)
            {   
                if(nums[half].value==target)
                {
                    return vector<int>({1, nums[half].index});
                }
                return vector<int>({0,half});
            }
            
            else if(nums[half].value<target)
            {
                return FindNumber(nums, target, half+1,end);
            }
            
            else
            {
                return FindNumber(nums, target, start,half);
            }
        }
};


class Solution {


public:
    vector<NumberWithIndex> arrayWithIndex(vector<int>& nums)
    {
        int length= nums.size();
        std::vector<NumberWithIndex> result;

        for (int i = 0; i < length; ++i)
        {
            result.push_back(NumberWithIndex(nums[i],i));
        }
        return result;

    }

public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
    Solution newObject;
    vector<NumberWithIndex> newArray= newObject.arrayWithIndex(nums);
    
     
    MergeSort SortObject;
    
    /*for(int i=0; i<newArray.size(); ++i)
        {
            int number=newArray[i].index;
            std::cout <<number << std::endl;
        }
    
    std::cout <<"xxxxxxxxxxxx" << std::endl;
    */
    newArray=SortObject.Sort(newArray);
    
    /*for(int i=0; i<newArray.size(); ++i)
        {
            int number=newArray[i].value;
            std::cout <<number << std::endl;
        }
    */
        
    Bisection BisectionObject;

    int foundSolution=0;
    int ind1=0;
    int ind2=newArray.size()-1;
    vector<int>result;
    while(foundSolution==0)
    {   
        
        int newTarget=target-newArray[ind1].value;
        vector<int> solution=BisectionObject.FindNumber(newArray, newTarget,ind1+1, ind2);

        if(solution[0]==1)
        {
            result={newArray[ind1].index,solution[1]};
            foundSolution=1;
        }
        else
        {
            ind1++;
            ind2=solution[1];
        }

    }
    return result;
    }   
};

int main() {
    
    vector<int> nums ={2,7,2,6,4,12,76,34,23,3,5,8};
    int target= 8;
    
    Solution SolutionObject;
    vector<int> result=SolutionObject.twoSum(nums, target);#Im adding something here too
    
    std::cout<<result[0]<<"x"<<result[1];
    
    return 0;
}

#Just to check if this is working properly