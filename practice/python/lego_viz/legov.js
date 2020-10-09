w = screen.availWidth
wm = w / 100

function magnify(x) {
    return x * wm
}

Colors = {};
Colors.names = {
    aqua: "#00ffff",
    azure: "#f0ffff",
    beige: "#f5f5dc",
    black: "#000000",
    blue: "#0000ff",
    brown: "#a52a2a",
    cyan: "#00ffff",
    darkblue: "#00008b",
    darkcyan: "#008b8b",
    darkgrey: "#a9a9a9",
    darkgreen: "#006400",
    darkkhaki: "#bdb76b",
    darkmagenta: "#8b008b",
    darkolivegreen: "#556b2f",
    darkorange: "#ff8c00",
    darkorchid: "#9932cc",
    darkred: "#8b0000",
    darksalmon: "#e9967a",
    darkviolet: "#9400d3",
    fuchsia: "#ff00ff",
    gold: "#ffd700",
    green: "#008000",
    indigo: "#4b0082",
    khaki: "#f0e68c",
    lightblue: "#add8e6",
    lightcyan: "#e0ffff",
    lightgreen: "#90ee90",
    lightgrey: "#d3d3d3",
    lightpink: "#ffb6c1",
    lightyellow: "#ffffe0",
    lime: "#00ff00",
    magenta: "#ff00ff",
    maroon: "#800000",
    navy: "#000080",
    olive: "#808000",
    orange: "#ffa500",
    pink: "#ffc0cb",
    purple: "#800080",
    violet: "#800080",
    red: "#ff0000",
    silver: "#c0c0c0",
    white: "#ffffff",
    yellow: "#ffff00"
};

Colors.random = function() {
    var result;
    var count = 0;
    for (var prop in this.names)
        if (Math.random() < 1/++count)
           result = prop;
    return result;
};

function addRect(start, end, color) {
    // two has convenience methods to create shapes.
    x = magnify((start + end) / 2)
    y = screen.availHeight / 2
    var rect = two.makeRectangle(x, y, magnify(end - start), 30);

    rect.fill = color;
    rect.opacity = 0.75;
    //rect.noStroke();
}

// Make an instance of two and place it on the page.
var elem = document.getElementById('draw-shapes');
var params = { width: screen.availWidth, height: screen.availHeight };
var two = new Two(params).appendTo(elem);

var colors = []
for (i = 0; i < 2; ++i) {
    colors.push(Colors.random())
    addRect(50, 60, colors[i])
}

// Don't forget to tell two to render everything
// to the screen
two.update();