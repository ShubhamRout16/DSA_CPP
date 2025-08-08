# Dynamic Memory Allocation in C: Common Errors and Solutions

## Problem: Removing Duplicate Elements from Array

### Original Problem
Design logic to remove duplicate elements from an array and return an array containing only unique elements.

---

## Critical Errors in Original Code

### 1. **Returning Local Array (Dangling Pointer)**

#### ❌ **WRONG Approach:**
```c
int* removeDup(int arr[], int n) {
    int uniqueArrEl[100];  // Local array on stack
    // ... fill array ...
    return uniqueArrEl;     // Returns address of destroyed memory
}
```

#### **Why This Doesn't Work:**
- **Stack Memory**: Local arrays are stored on the stack
- **Temporary Life**: Stack memory is destroyed when function ends
- **Dangling Pointer**: Returned address points to invalid memory
- **Undefined Behavior**: Accessing destroyed memory causes crashes/garbage data

#### **Memory Lifecycle:**
```
Function Execution:
┌─────────────────┐
│ Stack Frame     │
│ ┌─────────────┐ │
│ │ uniqueArrEl │ │ ← Valid memory
│ │ [100]       │ │
│ └─────────────┘ │
└─────────────────┘

Function Ends:
┌─────────────────┐
│ Stack Frame     │
│ ┌─────────────┐ │
│ │ DESTROYED   │ │ ← Memory gone!
│ │             │ │
│ └─────────────┘ │
└─────────────────┘

Main Function:
arr2[0] → Accessing destroyed memory → UNDEFINED BEHAVIOR!
```

### 2. **Incorrect Size Calculation**

#### ❌ **WRONG Approach:**
```c
int* arr2 = removeDup(arr, n);
int size2 = sizeof(arr2) / sizeof(arr2[0]);  // WRONG!
```

#### **Why This Doesn't Work:**
- `sizeof(arr2)` = size of pointer (4 or 8 bytes)
- `sizeof(arr2[0])` = size of int (4 bytes)
- Result: `8/4 = 2` or `4/4 = 1` (not actual array size)

#### **Example:**
```c
int* ptr = malloc(100 * sizeof(int));
printf("sizeof(ptr) = %zu\n", sizeof(ptr));        // 8 (pointer size)
printf("sizeof(ptr[0]) = %zu\n", sizeof(ptr[0]));  // 4 (int size)
printf("Calculated = %zu\n", sizeof(ptr)/sizeof(ptr[0])); // 2 (WRONG!)
```

---

## ✅ **Correct Solution: Dynamic Memory Allocation**

### **Fixed Approach:**

```c
int* removeDup(int arr[], int n, int* newSize) {
    // 1. Dynamic allocation on heap
    int* uniqueArrEl = (int*)malloc(n * sizeof(int));
    
    // 2. Error handling
    if (uniqueArrEl == NULL) {
        printf("Memory allocation failed!\n");
        *newSize = 0;
        return NULL;
    }
    
    // 3. Algorithm logic
    int uniqInd = 0;
    for (int i = 0; i < n; i++) {
        if (!isPresent(uniqueArrEl, uniqInd, arr[i])) {
            uniqueArrEl[uniqInd] = arr[i];
            uniqInd++;
        }
    }
    
    // 4. Return size separately
    *newSize = uniqInd;
    return uniqueArrEl;
}
```

### **Main Function:**
```c
int main() {
    // ... input array ...
    
    int newSize;
    int* arr2 = removeDup(arr, n, &newSize);
    
    // Error handling
    if (arr2 == NULL) {
        printf("Error: Could not remove duplicates!\n");
        return 1;
    }
    
    // Use array with known size
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr2[i]);
    }
    
    // 5. Memory cleanup
    free(arr2);
    return 0;
}
```

---

## **Why Dynamic Allocation Works**

### **Heap vs Stack Memory:**

| Aspect | Stack Memory | Heap Memory |
|--------|-------------|-------------|
| **Lifecycle** | Automatic (function scope) | Manual (until free()) |
| **Size** | Fixed at compile time | Dynamic at runtime |
| **Access** | Fast | Slower |
| **Management** | Automatic | Manual |

### **Memory Persistence:**
```
Function Execution:
┌─────────────────┐
│ Stack Frame     │
│ ┌─────────────┐ │
│ │ uniqueArrEl │ │ ← Points to heap
│ │ (pointer)   │ │
│ └─────────────┘ │
└─────────────────┘
         │
         ▼
┌─────────────────┐
│ Heap Memory     │
│ ┌─────────────┐ │
│ │ Allocated   │ │ ← Valid memory
│ │ Array       │ │
│ └─────────────┘ │
└─────────────────┘

Function Ends:
┌─────────────────┐
│ Stack Frame     │
│ ┌─────────────┐ │
│ │ DESTROYED   │ │ ← Pointer gone
│ │             │ │
│ └─────────────┘ │
└─────────────────┘
         │
         ▼
┌─────────────────┐
│ Heap Memory     │
│ ┌─────────────┐ │
│ │ STILL VALID │ │ ← Memory persists!
│ │ Array       │ │
│ └─────────────┘ │
└─────────────────┘
```

---

## **Best Practices for Dynamic Memory**

### 1. **Always Check Allocation**
```c
int* ptr = (int*)malloc(size * sizeof(int));
if (ptr == NULL) {
    // Handle allocation failure
    return NULL;
}
```

### 2. **Track Size Separately**
```c
int* removeDup(int arr[], int n, int* newSize) {
    // ... algorithm ...
    *newSize = actual_count;  // Return size via pointer
    return array;
}
```

### 3. **Always Free Memory**
```c
int* arr = malloc(size);
// ... use arr ...
free(arr);  // Clean up when done
```

### 4. **Error Handling**
```c
int* result = someFunction();
if (result == NULL) {
    // Handle error
    return 1;
}
```

---

## **Key Takeaways**

1. **Never return local arrays** - they become dangling pointers
2. **Use dynamic allocation** for returning arrays from functions
3. **Track size separately** - sizeof() doesn't work on pointers
4. **Always free memory** - prevent memory leaks
5. **Check for allocation failures** - handle errors gracefully
6. **Heap memory persists** - safe to return from functions
7. **Stack memory is temporary** - destroyed when function ends

---

## **Common Memory Errors to Avoid**

- ❌ Returning local arrays
- ❌ Using sizeof() on pointers
- ❌ Not checking malloc() return value
- ❌ Forgetting to free() allocated memory
- ❌ Accessing freed memory
- ❌ Memory leaks from unfreed allocations 