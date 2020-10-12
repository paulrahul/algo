'''
TODOs:
1. Make the scale magnification easier.
2. Add ability to treat Black as the default floor color.
'''

from collections import namedtuple
import random

from PIL import Image, ImageColor, ImageDraw

edge = namedtuple("edge", "index type")
block = namedtuple("block", "color start end")
MAG = 13                                                                                            
def solve(color_map, coord_map, y, im):
    draw = ImageDraw.Draw(im)
    draw.text((0, y + 5), "Seen from bottom", "Grey")

    y += 20
    solution = find_top_view(color_map, coord_map)
    for color, start, end in solution:                          
        #print "%s %d %d" % (color, start, end)
        draw_rect(start, end, y, color, im)

    draw.line((0, y + 20, 1300, y + 20), (128, 128, 128), 2)
    return y + 40

def find_top_view(color_map, coord_map):
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

    solution = []
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

        solution.append((new_color, prev_coord, curr_coord))
        if curr_type == "L":
            top_idx = curr_idx
            new_color = color_map[curr_idx].color
            prev_idx = curr_idx
        else: # Right edge
            color_map.pop(curr_idx)
            # new_color will be the new top most block's color.
            k = curr_idx - 1
            while (k >= 0 and
                   (k not in color_map or  # This color not yet encountered.
                    color_map[k].start >= curr_coord)):
                k -= 1
            if color_map and k >= 0:
                new_color = color_map[k].color
                top_idx = k
                prev_idx = k
            else:
                new_color = "Black"

        prev_coord = curr_coord
    
    return solution

def init_image():
    return Image.new('RGBA', (1400, 768), (128, 128, 128, 0))

def finalise_image(im):
    im.save('lego_visualisation.png', quality=95)

def draw_rect(start, end, y, color, im):
    #print "draw %d %d %d %s" % (start, end, y, color)
    start *= MAG
    end *= MAG

    draw = ImageDraw.Draw(im)
    draw.rectangle((start, y, end, y + 10), fill=color,
                    outline=(255, 255, 255))

if __name__ == "__main__":
    im = init_image()

    colors = set()
    color_map = {}  # coord index to block element
    coord_map = {}  # coordinate to edge element
    index = 0
    y = 10
    while True:
        try:
            inp = raw_input().split()
            l = len(inp)
            if l == 0:
                y = solve(color_map, coord_map, y, im)

                index = 0
                color_map.clear()
                coord_map.clear()
                continue

            rand_key = ImageColor.colormap.keys()[random.randint(0, len(ImageColor.colormap) - 1)]
            color = ImageColor.colormap[rand_key]
            while color in colors:
                rand_key = ImageColor.colormap.keys()[random.randint(0, len(ImageColor.colormap) - 1)]
                color = ImageColor.colormap[rand_key]
            if inp[0]:
                color = ImageColor.getrgb(inp[0]) + tuple((128,))

            for i in range(0, l / 2):
                start = int(inp[2 * i + 1])
                end = int(inp[2 * i + 2])
                color_map[index] = block(color, start, end) 
                coord_map[start] = edge(index, "L")
                coord_map[end] = edge(index, "R")

                draw_rect(start, end, y, color, im)

                index += 1
            y += 15
        except EOFError:
            break

    solve(color_map, coord_map, y, im)

    finalise_image(im)