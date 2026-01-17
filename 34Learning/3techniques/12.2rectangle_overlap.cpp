// given bottom left and top right coordinates of two rectangles i and j

// bottomLefti = (x1i, y1i)
// topRighti = (x2i, y2i)
// bottomLeftj = (x1j, y1j)
// topRightj = (x2j, y2j)

// overlapWidth = min(x2i, x2j) - max(x1i, x1j)
// overlapHeight = min(y2i, y2j) - max(y1i, y1j)
//If either width or height is ≤ 0, they don't overlap