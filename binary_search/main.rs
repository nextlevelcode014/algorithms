fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
    let mut left = 0;
    let mut right = arr.len().wrapping_sub(1);
    let mut steps = 0;

    while left <= right {
        steps += 1;
        let mid = left + (right - left) / 2;

        if arr[mid] == target {
            println!("steps: {}", steps);
            return Some(mid);
        } else if arr[mid] < target {
            left = mid + 1;
        } else {
            right = mid.wrapping_sub(1);
        }
    }

    None
}

fn main() {
    let arr = [
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    ];

    //   0 1 2 3 4 5 6 7 8
    let result = binary_search(&arr, 6);
    println!("{}", result.unwrap());
}
