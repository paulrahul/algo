from collections import namedtuple

edge = namedtuple("edge", "index type")
block = namedtuple("block", "color start end")

def solve(color_map, coord_map):
    sorted_idx = coord_map.keys()
    sorted_idx.sort()

    # Now, basically iterate over the sorted points where each point marks the
    # beginning of the color it belongs to. BUT, there's a catch - you always
    # move forward in the indices i.e. skip the bricks whose index is < the
    # previous block.
    l = len(sorted_idx)
    prev_coord = sorted_idx[0]
    prev_idx = coord_map[prev_coord].index
    new_color = color_map[prev_idx].color
    top_idx = prev_idx
    for i in range(1, l):
        curr_coord = sorted_idx[i]
        curr_idx = coord_map[sorted_idx[i]].index
        curr_type = coord_map[sorted_idx[i]].type

        if curr_type == "L" and curr_idx < prev_idx:
            # This won't really start a new color as another block eclipses
            # this.
            continue
        elif curr_type == "R" and curr_idx != top_idx:
            color_map.pop(curr_idx)
            continue

        print "%s %d %d" % (new_color, prev_coord, curr_coord)
        if curr_type == "L":
            top_idx = curr_idx
            new_color = color_map[curr_idx].color
            prev_idx = curr_idx
        else: # Right edge
            color_map.pop(curr_idx)
            # new_color will be the new top most block's color.
            if color_map:
                k = curr_idx - 1
                while (k >= 0 and k not in color_map or 
                       color_map[k].start >= curr_coord):
                    k -= 1
                new_color = color_map[k].color
                top_idx = k
                prev_idx = k
            else:
                new_color = "B"

        prev_coord = curr_coord
        
if __name__ == "__main__":
    color_map = {}  # coord index to block element
    coord_map = {}  # coordinate to edge element
    index = 0
    while True:
        try:
            inp = raw_input().split()
            l = len(inp)
            if l == 0:
                solve(color_map, coord_map)

                index = 0
                color_map.clear()
                coord_map.clear()
                continue

            color = inp[0]
            for i in range(0, l / 2):
                start = int(inp[2 * i + 1])
                end = int(inp[2 * i + 2])
                color_map[index] = block(color, start, end) 
                coord_map[start] = edge(index, "L")
                coord_map[end] = edge(index, "R")

                index += 1
        except EOFError:
            break

    solve(color_map, coord_map)
