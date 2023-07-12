#include <iostream>
#include <vector>

int alphaBitwise(std::vector<int>& array) {
    int n = array.size();
    int totalCount = 0;

    // Calculate the total count of set bits in all elements
    for (int i = 0; i < n; i++) {
        int count = 0;
        int num = array[i];

        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }

        totalCount += count;
    }

    // Check if the total count is greater than half the size of the array
    int halfSize = n / 2;
    int result = 0;

    if (totalCount > halfSize) {
        // Set all bits in the result
        for (int i = 0; i < 32; i++) {
            result |= (1 << i);
        }
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> array(n);

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    int alpha = alphaBitwise(array);

    std::cout << "The alpha bitwise of the array is: " << alpha << std::endl;

    return 0;
}

// bool isMaxOrder(TreeNode * root){
//         if(!root || (!root->left && !root->right)) return true;
//         if(!root->right) return (root->data > root->left->data);
//         return (root->data>root->left->data && root->data>root->right->data && isMaxOrder(root->right) && isMaxOrder(root->left));
//     }