fn reverse_each_word_ascii(mut s: String) -> String {
    let bytes = unsafe { s.as_bytes_mut() };
    let mut start = 0;

    for i in 0..=bytes.len() {
        if i == bytes.len() || bytes[i] == b' ' {
            let mut left = start;
            let mut right = i - 1;
            while left < right {
                bytes.swap(left, right);
                left += 1;
                right -= 1;
            }
            start = i + 1;
        }
    }

    s
}

fn reverse_each_word_in_string(s: String) -> String {
    let mut chars: Vec<char> = s.chars().collect();
    let len = chars.len();
    let mut start = 0;

    for i in 0..=len {
        if i == len || chars[i] == ' ' {
            let mut left = start;
            let mut right = i - 1;
            while left < right {
                chars.swap(left, right);
                left += 1;
                right -= 1;
            }
            start = i + 1;
        }
    }

    chars.into_iter().collect() 
}

fn reverse_each_word(s: &str) -> String {
    let mut result = String::with_capacity(s.len());
    let mut start = 0;

    let chars: Vec<char> = s.chars().collect();

    for (i, &ch) in chars.iter().enumerate() {
        if ch == ' ' {
            for j in (start..i).rev() {
                result.push(chars[j]);
            }
            result.push(' ');
            start = i + 1;
        }
    }

    for j in (start..chars.len()).rev() {
        result.push(chars[j]);
    }

    result
}

fn main() {
}


