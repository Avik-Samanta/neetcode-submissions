impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l <= r {
            let mut mid = (l + r) / 2;
            if nums[mid] < target {
                l = mid + 1;
            } else if nums[mid] > target {
                r = mid - 1;
            } else {
                return mid.try_into().unwrap();
            }
        }
        return -1;
    }
}
