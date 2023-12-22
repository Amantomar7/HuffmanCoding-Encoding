#include "Heap.c"

// This stores the binary string of all the character in the file
char CharArr[127][20];

// This is for writing the codes in the CharArr
void MakeArr(int arr[], int n, int Type) { 
    for (int i = 0; i < n; ++i) {
        if(arr[i] == 1) CharArr[Type][i] = '1';
        else CharArr[Type][i] = '0';
    }
} 

// THis is for if the given node if leaf or not
int isLeaf(struct HeapNode* root)  {
    return !(root->left) && !(root->right); 
}

void MakeCodes(struct HeapNode* root, int arr[], int top) { 
    // Making the huffman tree
    if (root->left) { 
        // if going to left give code 0
        arr[top] = 0; 
        MakeCodes(root->left, arr, top + 1); 
    } 
    if (root->right) { 
        // if going to right give code 1
        arr[top] = 1; 
        MakeCodes(root->right, arr, top + 1); 
    } 
    if (isLeaf(root)) { 
        // if leaf we got the char so add this code
        MakeArr(arr, top, root->Data); 
    } 
}

// (writing file, reading file)
void CodeTo(char fileName[], char fileName1[]) {
    FILE* WriteTo;
    WriteTo = fopen(fileName, "w");
    FILE* ReadFrom;
    char ch;
    ReadFrom = fopen(fileName1, "r");
    while(!feof(ReadFrom)) {
        ch = fgetc(ReadFrom);
        int sz = strlen(CharArr[ch]);
        for(int i = 0; i < sz; i++) {
            fputc(CharArr[ch][i], WriteTo);
        }
    }
    fclose(WriteTo);
    fclose(ReadFrom);
}
