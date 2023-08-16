class NumArray
{
private:
    vector<int> segTree; // Segment tree to store cumulative sums
    vector<int> nums;    // Original array of numbers
    int n;               // Size of the array

    // Build the segment tree
    void buildSegmentTree(int start, int end, int index)
    {
        if (start == end)
        {
            segTree[index] = nums[start]; // if start == end, then it is a leaf node and contains the value || example: [1,2,3,4] -> [1,2,3,4,0,0,0]
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * index + 1;  // Index of left child
        int rightChild = 2 * index + 2; // Index of right child

        buildSegmentTree(start, mid, leftChild);    // Recursively build left subtree
        buildSegmentTree(mid + 1, end, rightChild); // Recursively build right subtree

        segTree[index] = segTree[leftChild] + segTree[rightChild]; // Update parent with sum of children || example: [1,2,3,4] -> [10,3,7,1,2,3,4]
    }

    // Update a value in the segment tree
    void updateSegmentTree(int start, int end, int position, int value, int index)
    {
        if (start > end || position < start || position > end)
            return;

        if (start == end)
        {
            segTree[index] = value; // Update the leaf node with new value
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (position <= mid)
            updateSegmentTree(start, mid, position, value, leftChild); // Update left subtree
        else
            updateSegmentTree(mid + 1, end, position, value, rightChild); // Update right subtree

        segTree[index] = segTree[leftChild] + segTree[rightChild]; // Update parent with sum of children
    }

    // Query the sum in a given range
    int sumQuery(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int index)
    {
        if (queryStart > segmentEnd || queryEnd < segmentStart)
            return 0; // Range is completely outside the query range

        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
            return segTree[index]; // Range is completely inside the query range

        int mid = segmentStart + (segmentEnd - segmentStart) / 2;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        return sumQuery(queryStart, queryEnd, segmentStart, mid, leftChild) +
               sumQuery(queryStart, queryEnd, mid + 1, segmentEnd, rightChild); // Combine results from left and right subtrees
    }

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        n = (int)nums.size();
        segTree.resize(4 * n);         // Initialize the segment tree size
        buildSegmentTree(0, n - 1, 0); // Build the segment tree
    }

    void update(int index, int value)
    {
        updateSegmentTree(0, n - 1, index, value, 0); // Update a value in the segment tree
    }

    int sumRange(int left, int right)
    {
        return sumQuery(left, right, 0, n - 1, 0); // Query sum in the given range
    }
};

/*
    Tree representation of the segment tree for the array [1,2,3,4,5,6,7,8,9,10]
    The leaf nodes contain the values of the array
    The internal nodes contain the sum of the values of its children
    The root node contains the sum of all the values in the array
    The Diagram is given below

                10
            /        \
           6          4 
        /    \      /   \
       3     3    2     2  // Internal nodes containing sum of children 
      / \    / \  / \   / \
    1   2  3   4 5  6   7  8 // Leaf nodes 




*/
