with open("data.txt", "r") as f:
    x = [l.strip() for l in f]

blank_space_index = x.index('')
# generates list of fresh elements
range_ids = [list(map(int, l.split("-"))) for l in x[:blank_space_index]]
# elements to check
available = list(map(int, x[blank_space_index+1:]))
# check elements
count = 0
for item in available:
    for rng in range_ids:
        if item >= rng[0] and item <= rng[1]:
            count += 1
            break
    
print("Day 5 part 1: ", count)

range_ids = [list(range(l[0], l[1]+1)) for l in range_ids]
range_ids = set(range_ids)
count = len(range_ids)

print("Day 5 part 2: ", count)