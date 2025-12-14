#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
