#include "DecodingHuffmantree.c"

#define NEWLINE 10
int MAXLEN = 0;

/*
This is the main driver function of the huffman coding / decoding file
it includes 3 files -> Heap.c - This has all the working of the min heap
                    -> DecodingHuffmantree.c - this has the code for decoding of the file
                    -> MakeHuffmantree.c - this has the code for building huffman tree

*/

int main(int argc, char** args) {

    FILE* ptr;
    char ch;
    // Here reading the main file of text
    ptr = fopen("A.txt", "r");
    // data holds the char
    char data[200]; 
    // freq holds the frequency of the given character
    long freq[200];
    // Initializing freq to 0...
    for(int i = 0; i < 200; i++) freq[i] = 0;
    while(!feof(ptr)) {
        ch = fgetc(ptr);
        freq[ch] += 1;
        data[ch] = ch;
    }
    fclose(ptr);
    for(int i = 0; i < 127; i++) {
        if(freq[i] > 0) {
            MAXLEN++;
        }
    }
    // Making heap array
    struct MinHeap* HeapLis = CreateHeap(MAXLEN + 10);
    // Inserting elements to it
    InsertElements(HeapLis, data, freq, 127);
    // Building heap
    BuildHeap(HeapLis);
    
    int N = HeapLis->size; // Size of heap Now...

    // This is making of the huffman tree
    for(int i = 0; i < N - 1; i++) {
        struct HeapNode* left = ExtractMin(HeapLis);
        struct HeapNode* right = ExtractMin(HeapLis);
        struct HeapNode* top = NewNode('`', left->Freq + right->Freq);
        top->left = left;
        top->right = right;
        Insert(HeapLis, top);
    }

    int top = 0, arr[N + 100];
    // generating binary codes for all character
    MakeCodes(HeapLis->Nodes[0], arr, top);
    // writing codes to write.txx of the file A.txt
    CodeTo("write.txt", "A.txt");
    // Decoding file write.txt to newFile.txt
    decode("write.txt", HeapLis, "newFile.txt");

    return 0;
}