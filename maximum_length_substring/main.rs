use std::collections::HashMap;

fn max_substring_with_at_most_two_repeats_map(s: &str) -> usize {
    let chars: Vec<char> = s.chars().collect();
    let mut count = HashMap::new();
    let mut max_len = 0;
    let mut start = 0;

    for end in 0..chars.len() {
        *count.entry(chars[end]).or_insert(0) += 1;

        // Enquanto algum caractere tiver mais de 2 ocorrências
        while count[&chars[end]] > 2 {
            let entry = count.get_mut(&chars[start]).unwrap();
            *entry -= 1;
            start += 1;
        }

        max_len = max_len.max(end - start + 1);
    }

    max_len
}

fn max_substring_with_at_most_two_repeats_vec(s: &str) -> usize {
  let s = s.as_bytes(); // para acessar s[i] diretamente
  let mut count = [0; 26];
  let mut max_len = 0;
  let mut start = 0;

  for end in 0..s.len() {
      let idx = (s[end] - b'a') as usize;
      count[idx] += 1;

      // Enquanto algum caractere passar de 2 repetições
      while count[idx] > 2 {
          let idx_start = (s[start] - b'a') as usize;
          count[idx_start] -= 1;
          start += 1;
      }

      max_len = max_len.max(end - start + 1);
  }

  max_len
}

fn main() {
  let s = "abacaacb";
  let result = max_substring_with_at_most_two_repeats_vec(s);
  println!("{}", result);
}
