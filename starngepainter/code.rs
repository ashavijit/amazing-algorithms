use std::collections::{HashSet, HashMap, VecDeque};

impl Solution {
    pub fn is_printable(grid: Vec<Vec<i32>>) -> bool {
        // Step 1: Finding Distant Colors in the Grid
        // Create a HashSet 'st' to store distinct colors in the grid.
        let mut st: HashSet<i32> = HashSet::new();
        let n = grid.len();
        let m = grid[0].len();
        for i in 0..n {
            for j in 0..m {
                st.insert(grid[i][j]);
            }
        }

        // Step 2: Finding Coordinates of Colors
        // Create HashMaps 'row' and 'col' to store the starting and ending row and column coordinates for each color.
        let mut row: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut col: HashMap<i32, Vec<i32>> = HashMap::new();

        for it in &st {
            let mut mn1 = n as i32;
            let mut mx1 = 0;
            let mut mn2 = m as i32;
            let mut mx2 = 0;

            // Iterate through the grid to find the starting and ending row and column coordinates for color 'it'.
            for i in 0..n {
                for j in 0..m {
                    if grid[i][j] == *it {
                        mn1 = mn1.min(i as i32);
                        mx1 = mx1.max(i as i32);
                        mn2 = mn2.min(j as i32);
                        mx2 = mx2.max(j as i32);
                    }
                }
            }

            // Store the coordinates in the HashMaps.
            row.entry(*it).or_insert(Vec::new()).push(mn1);
            row.get_mut(it).unwrap().push(mx1);
            col.entry(*it).or_insert(Vec::new()).push(mn2);
            col.get_mut(it).unwrap().push(mx2);
        }

        // Step 3: Building the Dependency Graph
        // Create a 2D vector 'graph' to represent the dependency graph between colors.
        let mut graph: Vec<Vec<i32>> = vec![vec![]; 61];
        let mut indegree: [i32; 61] = [0; 61];

        for it in &st {
            let mnr = row[it][0];
            let mxr = row[it][1];
            let mnc = col[it][0];
            let mxc = col[it][1];

            // Create a HashSet 'st2' to store colors that are inside the rectangle of color 'it'.
            let mut st2: HashSet<i32> = HashSet::new();
            for i in mnr..=mxr {
                for j in mnc..=mxc {
                    if *it != grid[i as usize][j as usize] {
                        st2.insert(grid[i as usize][j as usize]);
                    }
                }
            }

            // Increment the in-degree of color 'it' based on the number of colors inside its rectangle.
            indegree[*it as usize] = st2.len() as i32;

            // Add edges from colors inside the rectangle to color 'it'.
            for it2 in &st2 {
                graph[*it2 as usize].push(*it);
            }
        }

        // Step 4: Standard Topological Sort
        // Perform a topological sort using a Queue 'q' to check if there is a valid sequence of printing operations.
        let mut q: VecDeque<i32> = VecDeque::new();
        let mut count = 0;
        for it in &st {
            if indegree[*it as usize] == 0 {
                q.push_back(*it);
            }
        }
        while !q.is_empty() {
            let u = q.pop_front().unwrap();
            count += 1;
            for v in &graph[u as usize] {
                indegree[*v as usize] -= 1;
                if indegree[*v as usize] == 0 {
                    q.push_back(*v);
                }
            }
        }

        // Step 5: Checking the Result
        // If the 'count' variable is equal to the number of distinct colors in the 'targetGrid',
        // it means all colors were successfully processed in the topological sort, and we can return true.
        // Otherwise, we return false.
        count == st.len() as i32
    }
}
