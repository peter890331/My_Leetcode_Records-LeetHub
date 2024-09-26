class MyCalendar {

    map<int, int> intervals; // Stores intervals with start as key and end as value

public:

    // 構造函數。
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next = intervals.lower_bound(start); // Find next interval
        // 檢查與下一個區間是否有重疊。
        if (next != intervals.end() && next->first < end) {
            return false; // Overlaps with next interval
        }
        // 檢查與上一個區間是否有重疊。
        if (next != intervals.begin() && prev(next)->second > start) {
            return false; // Overlaps with previous interval
        }
        intervals[start] = end; // No overlap, add interval
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// AlgoArtisan's solution.
// lower_bound：找出vector中「大於或等於」val的「最小值」的位置；返回一个迭代器，指向键值 >= key 的第一个元素 。
// upper_bound：找出vector中「大於」val的「最小值」的位置；返回一个迭代器，指向键值 > key 的第一个元素 。
// prev() 是用來返回一個迭代器的前一個位置。