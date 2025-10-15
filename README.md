# rpi-pixels

A lightweight utility class for managing and manipulating **RGB pixel buffers** in Node.js — perfect for use with LED matrices, NeoPixel strips, or any low-level pixel rendering system (like [rpi-ws281x](https://www.npmjs.com/package/rpi-ws281x)).

It provides easy color creation (RGB, HSL, CSS color names), pixel indexing, fill operations, and optional gamma correction.

---

## Installation

```bash
npm install rpi-pixels
```

---

## Usage

```javascript
const Pixels = require('rpi-pixels');

// Create a pixel grid, e.g. 8×8
const pixels = new Pixels({ width: 8, height: 8 });

// Fill entire grid with solid red
pixels.fillRGB(255, 0, 0);

// Set a single pixel (x=2, y=3) to green
pixels.setPixelRGB(2, 3, 0, 255, 0);

// Use color names or HSL values
pixels.fill('skyblue');
pixels.setPixelHSL(0, 0, 120, 50, 50);

// Apply gamma correction (optional)
const corrected = Pixels.gammaCorrect(pixels.pixels, 2.2);

// Send to your LED driver, e.g. rpi-ws281x
// ws281x.render(corrected);
```

---

## API Reference

### new Pixels({ width, height })
Creates a pixel buffer.

| Parameter | Type | Description |
|------------|------|-------------|
| width | number | Number of pixels per row |
| height | number | Number of pixels per column |

---

### Properties

| Property | Type | Description |
|-----------|------|-------------|
| width | number | Width of the pixel grid |
| height | number | Height of the pixel grid |
| pixels | Uint32Array | Raw pixel buffer (0xRRGGBB format) |

---

### Color helpers

| Method | Description |
|---------|-------------|
| RGB(r, g, b) | Returns a 0xRRGGBB integer. |
| HSL(h, s, l) | Returns a 0xRRGGBB integer using HSL values (requires `color` package). |
| color(name) | Returns a 0xRRGGBB integer from a CSS color name. |

---

### Fill operations

| Method | Description |
|---------|-------------|
| fill(color) | Fills all pixels with the given color (string or 0xRRGGBB). |
| fillRGB(r, g, b) | Fills all pixels with an RGB color. |
| fillHSL(h, s, l) | Fills all pixels using HSL values. |
| clear() | Clears all pixels (sets to black). |

---

### Pixel operations

| Method | Description |
|---------|-------------|
| getIndex(x, y) | Returns the linear index for a coordinate. |
| setPixel(x, y, color) | Sets a pixel using a numeric or string color. |
| getPixel(x, y) | Returns the numeric color at given coordinates. |
| setPixelRGB(x, y, r, g, b) | Sets a pixel using RGB values. |
| setPixelHSL(x, y, h, s, l) | Sets a pixel using HSL values. |

---

### Static methods

| Method | Description |
|---------|-------------|
| Pixels.gammaCorrect(pixels, gamma) | Applies gamma correction to a Uint32Array of pixels. Default gamma is 2.2. |

Example:

```javascript
const corrected = Pixels.gammaCorrect(pixels.pixels, 2.0);
```

---

## Notes

- All colors are stored as **0xRRGGBB** integers.  
- `Color` from [npm:color](https://www.npmjs.com/package/color) is used for color parsing and conversion.  
- Gamma correction is optional and non-destructive (returns a new Uint32Array).

---

## License

MIT © Magnus Egelberg  
https://github.com/magnusegelberg/rpi-pixels
