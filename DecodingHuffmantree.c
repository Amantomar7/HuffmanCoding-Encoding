#include "MakeHuffmantree.c"

// decoding the huffman tree
// decode(filename to read from, HeapNode, fileName to write to)
void decode(char fileName[], struct MinHeap* HeapLis, char fileName1[]) {

    FILE* BinaryFile, *WriteTo;
    BinaryFile = fopen(fileName, "r");
    WriteTo = fopen(fileName1, "w");

    char ch;
    // Using the root of the huffman tree
    struct HeapNode* root = HeapLis->Nodes[0];
    while(!feof(BinaryFile)) {
        ch = fgetc(BinaryFile);
        if(ch == '0') {
            // to the left child
            root = root->left;
        }
        else root = root->right; // To the right child

        if(root->left == NULL && root->right == NULL) {
            fputc(root->Data, WriteTo); // write to file of leaf Node is found
            root = HeapLis->Nodes[0];
        }
    }
    fclose(BinaryFile);
    fclose(WriteTo);
}