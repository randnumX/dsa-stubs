#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2) {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution {
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Creating an instance of Solution class
    Solution sol;
    
    // Function call to flatten the linked list
    ListNode* flattened = sol.flattenLinkedList(head);
    
    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}

// Next
#include <bits/stdc++.h> 

using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        // Create dummy node to serve as head of merged list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            /*Compare elements of both lists 
            and link the smaller node 
            to the merged list*/
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move the temporary pointer to the next node
            temp = temp->next; 
        }

        /*If any list still has 
        remaining elements append 
        them to the merged list*/
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        // Return the merged list starting 
        // from the next of the dummy node
        return dummyNode->next;
    }

    // Function to find the middle of a linked list
    ListNode* findMiddle(ListNode* head) {
        // If the list is empty or has only one node, 
        // the middle is the head itself
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Initializing slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

       /* Move the fast pointer twice as fast as the slow pointer
        When the fast pointer reaches the end, the slow pointer 
        will be at the middle*/
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Function to perform merge sort on a linked list
    ListNode* sortList(ListNode* head) {
        /*Base case: if the list is empty or has only one node, 
        it is already sorted, so return the head*/
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Find middle of list using findMiddle function
        ListNode* middle = findMiddle(head);
        
        // Divide the list into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        
        // Recursively sort left and right halves
        left = sortList(left);
        right = sortList(right);
        
        // Merge the sorted halves using the 
        // mergeTwoSortedLinkedLists function
        return mergeTwoSortedLinkedLists(left, right);
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->val << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Linked List: 3 2 5 4 1
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution solution;
    // Sort the linked list
    head = solution.sortList(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r) {
        val = data1;
        next = next1;
        random = r;
    }
};

class Solution {
public:
    // Insert a copy of each node in between the original nodes
    void insertCopyInBetween(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* nextElement = temp->next;
            // Create a new node with the same data
            ListNode* copy = new ListNode(temp->val);
            
            copy->next = nextElement;
            
            temp->next = copy;
            
            temp = nextElement;
        }
    }

    // Function to connect random pointers of the copied nodes
    void connectRandomPointers(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            // Access the copied node
            ListNode* copyNode = temp->next;
            
            /*If the original node has a random pointer
            point the copied node's random to the 
            corresponding copied random node
            set the copied node's random to null 
            if the original random is null*/
            if (temp->random) {
                
                copyNode->random = temp->random->next;
            } else {
                
                copyNode->random = NULL;
            }
            
            // Move to next original node
            temp = temp->next->next;
        }
    }

    // Function to retrieve the deep copy of the linked list
    ListNode* getDeepCopyList(ListNode* head) {
        ListNode* temp = head;
        // Create a dummy node
        ListNode* dummyNode = new ListNode(-1);
        // Initialize a result pointer
        ListNode* res = dummyNode;

        while (temp != NULL) {
            /*Creating a new List by 
            pointing to copied nodes*/
            res->next = temp->next;
            res = res->next;

            /*Disconnect and revert back 
            to the initial state of the 
            original linked list*/
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        /*Return the deep copy 
        of the list starting 
        from the dummy node*/
        return dummyNode->next;
    }

    // Function to clone the linked list
    ListNode* copyRandomList(ListNode* head) {
        // If the original list is empty, return null
        if (!head) return nullptr;

        // Insert nodes in between
        insertCopyInBetween(head);
        // Connect random pointers
        connectRandomPointers(head);
        // Retrieve deep copy of inked list
        return getDeepCopyList(head);
    }
};

// Function to print the cloned linked list
void printClonedLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << "Data: " << head->val;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        // Move to the next node
        head = head->next;
    }
}

int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    ListNode* head = new ListNode(7);
    head->next = new ListNode(14);
    head->next->next = new ListNode(21);
    head->next->next->next = new ListNode(28);

    // Assigning random pointers
    head->random = head->next->next; // 7 -> 21
    head->next->random = head; // 14 -> 7
    head->next->next->random = head->next->next->next; // 21 -> 28
    head->next->next->next->random = head->next; // 28 -> 14

    // Print the original linked list
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Solution solution;
    ListNode* clonedList = solution.copyRandomList(head);

    // Print the cloned linked list
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// Definition of doubly linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode* next1, ListNode* prev1) {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    // Function to delete all occurrences of a target value
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;
        
        while (temp != NULL) {
            if (temp->val == target) {
                // Update head if needed
                if (temp == head) {
                    head = temp->next;
                }
                
                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                // Update next node's previous
                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }
                
                // Update previous node's next
                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                }

                // Delete the current node
                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
        
        return head;
    }
};

// Function to print doubly linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a new node
ListNode* newNode(int data) {
    ListNode* node = new ListNode(data);
    return node;
}

int main() {
    // Creating doubly linked list
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Delete all occurrences of 2
    Solution sol;
    head = sol.deleteAllOccurrences(head, 2);

    // Print modified list
    cout << "Modified list: ";
    printList(head);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// Definition of Single Linked List
struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode* next1, ListNode* prev1) {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    // To remove duplicates from a sorted doubly linked list
    ListNode* removeDuplicates(ListNode* head) {
        ListNode* temp = head;
        
        // Traverse the list
        while (temp != NULL && temp->next != NULL) {
            ListNode* nextNode = temp->next;
            
            // Remove all duplicate nodes
            while (nextNode != NULL && nextNode->val == temp->val) {
                // Store the duplicate node
                ListNode* duplicate = nextNode;
                // Move to the next node
                nextNode = nextNode->next;
                // Delete the duplicate node
                delete duplicate;
            }
            
           /* Link the current node 
           to the next non-duplicate node*/
            temp->next = nextNode;
            /*Update previous pointer 
            of next non-duplicate node*/
            if (nextNode != NULL) {
                nextNode->prev = temp;
            }
            
            // Move to the next node
            temp = temp->next;
        }
        
        return head;
    }
};

// Function to print doubly linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a new node
ListNode* newNode(int data) {
    ListNode* node = new ListNode(data);
    return node;
}

int main() {
    // Creating a sorted doubly linked list:
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(2);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    Solution sol;
    head = sol.removeDuplicates(head);

    // Print modified list
    cout << "Modified list: ";
    printList(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the length of the
    longest substring with at most k zeros */
    int longestOnes(vector<int>& nums, int k) {
        
        // Length of the input array
        int n = nums.size();
        
        // Pointers for sliding window approach
        int l = 0, r = 0;
        
        /* Variables to count zeros
        and store maximum length */
        int zeros = 0, maxLen = 0;
               
        /* Iterate through the array 
        using sliding window approach */
        while (r < n) {
            
            if(nums[r] == 0) zeros++;
            
            if (zeros > k) {
                if (nums[l] == 0) {
                    
                    /* Decrement zeros count
                    when moving left pointer */
                    zeros--; 
                }
                l++;
            }
            if(zeros <= k){
                /* Calculate the length 
                of current substring */
                int len = r - l + 1;
            
                /* Update maxLen if the current
                substring length is greater */
                maxLen = max(maxLen, len);
            }
            r++;  
        }
        
        // Return the maximum length
        return maxLen; 
    }
};

int main() {
    vector<int> input = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;  
    
    // Create an instance of Solution class
    Solution sol;
    
    int length = sol.longestOnes(input, k);
    
    // Print the result
    cout << "Length of longest substring with at most " << k << " zeros: " << length << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the maximum
    fruits the basket can have */
    int totalFruits(vector<int>& fruits) {
        
        // Length of the input array
        int n = fruits.size();  
        
        /* Variable to store the 
        maximum length of substring*/
        int maxLen = 0;  
        
        /* Map to track the count of each
        fruit type in the current window*/
        unordered_map<int, int> mpp;
        
        // Pointers for the sliding window approach
        int l = 0, r = 0;
        
        while(r < n){
            mpp[fruits[r]]++;
            
            /* If number of different fruits exceeds
             2 shrink the window from the left*/
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            
            /* If number of different fruits 
            is at most 2, update maxLen*/
            if(mpp.size() <= 2){
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        
        // Return the maximum fruit
        return maxLen;
    }
};

int main() {
    vector<int> input = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};  
    
    // Create an instance of Solution class
    Solution sol;
    
    int length = sol.totalFruits(input);
    
    // Print the result
    cout << "Maximum fruits the can have is: " << length << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the maximum length of 
    substring with at most k distinct characters */
    int kDistinctChar(string& s, int k) {
        
        // Length of the input string
        int n = s.size();  
        
        /* Variable to store the 
        maximum length of substring*/
        int maxLen = 0;  
        
        /* Map to track the count of each
        character in the current window*/
        unordered_map<char, int> mpp;
        
        // Pointers for the sliding window approach
        int l = 0, r = 0;
        
        while(r < n){
            mpp[s[r]]++;
            
            /* If number of different characters exceeds
             k, shrink the window from the left*/
            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            
            /* If number of different characters 
            is at most k, update maxLen*/
            if(mpp.size() <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        
        // Return the maximum length
        return maxLen;
    }
};

int main() {
    string s = "aaabbccd";  
    int k = 2;
    
    // Create an instance of Solution class
    Solution sol;
    
    int length = sol.kDistinctChar(s, k);
    
    // Print the result
    cout << "Maximum length of substring with at most " << k << " distinct characters: " << length << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*Function to find the longest substring 
     with at most k characters replaced*/
    int characterReplacement(string s, int k) {
        
        /* Variable to store the maximum
        length of substring found*/
        int maxLen = 0;
        
        /* Variable to track the maximum frequency
        of any single character in the current window*/
        int maxFreq = 0;
        
        //Pointers to maintain the current window [l, r]
        int l = 0, r = 0; 
        
        // Hash array to count frequencies of characters
        int hash[26] = {0};  

        // Iterate through each starting point of substring
        while (r < s.size()) {

            /* Update frequency of current 
            character in the hash array*/
            hash[s[r] - 'A']++;
            
            // Update max frequency encountered
            maxFreq = max(maxFreq, hash[s[r] - 'A']); 
            
            // Check if current window is invalid 
            if ((r - l + 1) - maxFreq > k) {
                
                /* Slide the left pointer to
                make the window valid again*/
                hash[s[l] - 'A']--;  
                
                // Move left pointer forward
                l++; 
                
                
            }
            
            /* Update maxLen with the length 
            of the current valid substring*/
            maxLen = max(maxLen, r - l + 1);
            
            // Move right pointer forward to expand the window
            r++;
        }

        /* Return the maximum length of substring
        with at most k characters replaced*/
        return maxLen;
    }
};

int main() {
    string s = "AABABBA";
    int k = 2;

    // Create an instance of Solution class
    Solution sol;

    int length = sol.characterReplacement(s, k);

    // Print the result
    cout << "Maximum length of substring with at most " << k << " characters replaced: " << length << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the minimum length 
    substring in string s that contains
    all characters from string t. */
    string minWindow(string s, string t) {
        
        /* Variable to store the minimum 
        length of substring found */
        int minLen = INT_MAX;
        
        /* Variable to store the starting index
        of the minimum length substring */
        int sIndex = -1;
        
        /* Array to count frequencies
        of characters in string t*/
        int hash[256] = {0};
        
        // Count the frequencies of characters in t
        for (char c : t) {
            hash[c]++;
        }
            
        int count = 0;
        int l = 0, r = 0;
        
        // Iterate through current window 
        while (r < s.size()) {
            // Include the current character in the window
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;
                
            /* If all characters from t 
            are found in current window */
            while (count == t.size()) {
                    
                /* Update minLen and sIndex
                if current window is smaller */
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                
                // Remove leftmost character from window
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        
        // Return minimum length substring from s
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};

int main() {
    string s = "ddaaabbca";
    string t = "abc";

    // Create an instance of Solution class
    Solution sol;

    string ans = sol.minWindow(s, t);

    // Print the result
    cout << "Minimum length substring containing all characters from \"" << t << "\" is: " << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the number of substrings 
    containing all characters 'a', 'b', 'c' in string s. */
    int numberOfSubstrings(string s) {
        
        /* Array to store the last seen
        index of characters 'a', 'b', 'c'*/
        int lastSeen[3] = {-1, -1, -1};
        
        int count = 0;
        
        // Iterate through each character in string s
        for (int i = 0; i < s.size(); ++i) {
            
            // Update lastSeen index for 
            lastSeen[s[i] - 'a'] = i;
            
            /* Check if all characters 'a', 
            'b', 'c' have been seen*/
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                
                /* Count valid substrings 
                ending at current index*/
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        
        // Return total count of substrings
        return count;
    }
};

int main() {
    string s = "bbacba";

    // Create an instance of Solution class
    Solution sol;
    
    int ans = sol.numberOfSubstrings(s);

    // Print the result
    cout << "Number of substrings containing 'a', 'b', 'c' in \"" << s << "\" is: " << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the number of 
    subarrays with sum equal to `goal`*/
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        /*Calculate the number of subarrays with 
        sum exactly equal to `goal` by using the 
        difference between subarrays with sum less
        than or equal to `goal` and those with sum
        less than or equal to `goal-1`*/
        return numSubarraysWithSumLessEqualToGoal(nums, goal) - numSubarraysWithSumLessEqualToGoal(nums, goal - 1);
    }
    
private:
    /* Helper function to find the number of 
    subarrays with sum less than or equal to `goal`*/
    int numSubarraysWithSumLessEqualToGoal(vector<int>& nums, int goal) {
        
        /* If goal is negative, there 
        can't be any valid subarray sum*/
        if (goal < 0) return 0;
        
        //Pointers to maintain the current window
        int l = 0, r = 0; 
        
        /* Variable to track the current 
        sum of elements in the window*/
        int sum = 0;      
        
        // Variable to count the number of subarrays
        int count = 0;   
        
        /* Iterate through the array 
        using the right pointer `r`*/
        while (r < nums.size()) {
            sum += nums[r]; 
            
            /* Shrink the window from the left
            side if the sum exceeds `goal`*/
            while (sum > goal) {
                sum -= nums[l];  
                
                // Move the left pointer `l` forward
                l++;            
            }
            
            /* Count all subarrays ending at
            `r` that satisfy the sum condition*/
            count += (r - l + 1);
            
            // Move the right pointer `r` forward 
            r++; 
        }
        
        // Return the total count of subarrays
        return count;
    }
};

int main() {
    vector<int> nums = {1, 0, 0, 1, 1, 0};
    int goal = 2;
    
    // Create an instance of Solution class
    Solution sol;
    
    int ans = sol.numSubarraysWithSum(nums, goal);

    // Print the result
    cout << "Number of substrings with sum \"" << goal << "\" is: " << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the number of subarrays
    nice subarrays with k odd numbers*/
    int numberOfOddSubarrays(vector<int>& nums, int k) {
        
        /*Calculate the number of subarrays with 
        sum exactly equal to k by using the 
        difference between subarrays with sum less
        than or equal to k and those with sum
        less than or equal to k-1*/
        return helper(nums, k) - helper(nums, k - 1);
    }
    
private:
    /* Helper function to find the number of 
    subarrays with sum less than or equal to k*/
    int helper(vector<int>& nums, int k) {
        
        /* If goal is negative, there 
        can't be any valid subarray sum*/
        if (k < 0) return 0;
        
        //Pointers to maintain the current window
        int l = 0, r = 0; 
        
        /* Variable to track the current 
        sum of elements in the window*/
        int sum = 0;      
        
        // Variable to count the number of subarrays
        int count = 0;   
        
        /* Iterate through the array 
        using the right pointer `r`*/
        while (r < nums.size()) {
            sum = sum + nums[r] % 2; 
            
            /* Shrink the window from the left
            side if the sum exceeds k*/
            while (sum > k) {
                sum = sum -  nums[l] % 2;  
                
                // Move the left pointer `l` forward
                l++;            
            }
            
            /* Count all subarrays ending at
            `r` that satisfy the sum condition*/
            count += (r - l + 1);
            
            // Move the right pointer `r` forward 
            r++; 
        }
        
        // Return the total count of subarrays
        return count;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 1;
    
    // Create an instance of Solution class
    Solution sol;
    
    int ans = sol.numberOfOddSubarrays(nums, k);

    // Print the result
    cout << "Number of nice substrings with \"" << k << "\" odd numbers is: " << ans << endl;

    return 0;
}
