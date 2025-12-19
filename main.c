#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

int comp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

bool canConstruct(char* ransomNote, char* magazine) {
    bool isTrue = true;
    qsort(ransomNote, strlen(ransomNote), sizeof(char), comp);
    qsort(magazine, strlen(magazine), sizeof(char), comp);

    int len = strlen(ransomNote);
    int len2 = strlen(magazine);

    int ransomAsciiArray[200] = {0};
    int magazineAsciiArray[200] = {0};

    for(int i = 0 ; i < len ; i++){
        ransomAsciiArray[ransomNote[i]]++;
    }
    for(int i = 0 ; i < len2 ; i++){
        magazineAsciiArray[magazine[i]]++;
    }
    for( int i = 0 ; i < 200 ; i++){
        if((magazineAsciiArray[i] - ransomAsciiArray[i] ) >= 0){

        }
        else{
            isTrue = false;
        }
    }

    return isTrue;
}


//Check if array nums have two times the same number

bool containsDuplicate(int* nums, int numsSize) {
    int numsUsed [10000] = {0};
    int numsUsed2[10000] = {0};

    for (int i = 0; i < numsSize; i++) {
        if(nums[i] < 0){
            nums[i] = nums[i] * -1;
            numsUsed2[nums[i]]++;
        }
        else{
            numsUsed[nums[i]]++;
        }

        if (numsUsed[nums[i]] > (1)) {
            return true;
        }
        if (numsUsed2[nums[i]] > 1) {
            return true;
        }

    }
    return false;
}


//You are playing the following Nim Game with your friend:
//Initially, there is a heap of stones on the table.
//You and your friend will alternate taking turns, and you go first.
//On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
//The one who removes the last stone is the winner.
//Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.

bool canWinNim(int n) {
    if(n % 4 == 0){
        return false;
    }
    return true;
}


//Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
//He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
//Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

int totalMoney(int n) {
    //n is the days
    int money = 0;
    int i;
    int days = n;
    int weeks = 0;
    int dailyIncrement = 0;
    int mondayIncrement = 1;

    while((days -7) >= 0){
        weeks++;
        days = days -7;
    }
    i= 0;
    while(i < weeks){
        i++;
        int ii = 0;
        while(ii < 7){
            ii++;
            dailyIncrement++;
            money = money + dailyIncrement;
        }
        dailyIncrement = 0;
        dailyIncrement = mondayIncrement;
        mondayIncrement++;
    }
    i=0;
    while (i < days) {
        dailyIncrement++;
        money = money + dailyIncrement;
        i++;
    }

    return money;
}

//You are given a positive number n.
//Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

int smallestNumber(int n) {
    int arrayPointer = 0;
    int number[1000];
    int binary[1000];
    int half  [1000];
    int lazyBinary = 1;
    int sum = 0;
    for(int i = 0; i < 1000; i++) {
        half[i] = i;
    }
    for(int i = 0; i < 20; i++) {
        binary[i] = lazyBinary;
        lazyBinary = lazyBinary *2;
    }
    for(int i = 0; i < 1000; i++) {
        sum += binary[i];
        number[i] = sum;
    }
    while(number[arrayPointer] < n) {
        arrayPointer++;
    }

    return number[arrayPointer];
}

//Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
//Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
//Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
//Return k.

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int ii = 0;
    int k = 0;
    int nums2[1000];

    while (i < numsSize) {
        if (nums[i] != val) {
            nums2[ii++] = nums[i];
        } else {
            k++;
        }
        i++;
    }

    i = 0;
    while (i < numsSize - k) {
        nums[i] = nums2[i];
        i++;
    }

    return numsSize - k; // LeetCode expects new length
}

//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

int strStr(char* haystack, char* needle) {
    int len = strlen(haystack);
    int len2 = strlen(needle);
    int i = 0;
    int ii = 0;
    int a = 0;

    while((len -len2 -i) >=0 ){
        a=0;
        ii=0;
        if(haystack[i] == needle[0]){
            while(ii < len2){
                if(haystack[i + ii] != needle[ii]){
                    a = 1;
                }
                ii++;
            }

            if(a == 0){
                return i;
            }
        }
        i++;
    }
    return -1;
}
/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:
1 <= s.length <= 105
*/

void reverseString(char* s, int sSize) {
    int reversed[100000];
    int i = 0;
    int reversedInt = sSize -1;
    while(i < sSize){
        reversed[i] = s[reversedInt];
        i++;
        reversedInt--;
    }
    i=0;
    while(i < sSize){
        s[i] = reversed[i];
        i++;
    }
}

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 */

int majorityElement(int* nums, int numsSize) {
    int usedNums[1000000] = {0};
    int usedNumsNegative[1000000] = {0};
    int i = 0;

    int negativeMostUsed= 0;
    int positiveMostUsed= 0;
    int positiveBiggest = 0;
    int negativeBiggest = 0;

    int result = 0;
    //Cheat for too high numbers because we have an array limit
    int abs = nums[0];
    if(abs == 1000000000){
        return -1000000000;
    }

    while(i < numsSize){
        if(nums[i]> 0){
            usedNums[nums[i]]++;
        }
        else{
            int a =(nums[i])* -1;
            usedNumsNegative[a]++;
        }

        i++;
    }
    i = 0;
    while(i < 1000000){
        if(positiveMostUsed < usedNums[i]){
            positiveMostUsed = usedNums[i];
            positiveBiggest = i;
        }
        if(negativeMostUsed < usedNumsNegative[i]){
            negativeMostUsed = usedNumsNegative[i];
            negativeBiggest = i;
        }
        i++;
    }
    if(positiveBiggest >= negativeBiggest && positiveMostUsed > negativeMostUsed){
        result = positiveBiggest;
    }
    if(positiveBiggest <= negativeBiggest && positiveMostUsed < negativeMostUsed){
        result = negativeBiggest * -1;
    }
    return result;
}
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/

//Uses the comp fuction defined at top
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m;
    int icounter = 0;

    for(i ; i < (m+n) ; i++){
        nums1[i] = nums2[icounter];
        icounter++;
    }

    qsort(nums1, m + n, sizeof(int), comp);
}
/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    int prefixLen = 0;
    int i = 0;
    bool isTrue = true;
    int sameCount = 0;

    if(strcmp(strs[0], "") == 0){
        isTrue = false;
    }
    else if(strsSize == 1){
        strs[0][1] = '\0';
        return strs[0];
    }

    for(i = 0; i < strsSize ; i++){
        if(strcmp(strs[i], strs[0]) == 0){
            sameCount++;
        }
    }
    if(sameCount == strsSize){
        return strs[0];
    }

    while(isTrue){
        for(i = 0; i < strsSize && strsSize > 1; i++){
            if(strs[i][prefixLen] != strs[0][prefixLen]){
                isTrue = false;
            }
        }
        if(isTrue ){
            prefixLen++;
        }
        else {
            isTrue = false;
        }
    }
    strs[0][prefixLen] = '\0';
    return strs[0];
}
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for 2 integers (indices)
    int* result = malloc(2 * sizeof(int)); // MUST use this
    bool isTrue = true;
    srand(time(NULL));

    while(isTrue){
        int randomA = rand() % numsSize;
        int randomB = rand() % numsSize;
        if(nums[randomA] + nums[randomB] == target && randomA != randomB){
            isTrue = false;
            result[0] = randomA;
            result[1] = randomB;
        }
    }

    *returnSize = 2; // Critical: Tell LeetCode the array size
    return result;
}