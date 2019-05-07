/*
 Given a playfield that has width columns, and there are blocks falling from above similar to Tetris. All blocks are rectangle in shape and is defined by the following class:

class Block {
    int left;
    int right;   // inclusive. block's width = (right - left + 1)
    int height;
}
Where 0 <= left < right < width.

Implement the following FallingBlock class:

class FallingBlock {
    public FallingBlock(int width);
    public void fallBlock(Block block);
    // get the maximum height of all blocks.
    public int getMaxHeight();
}
Example:

FallingBlock obj = new FallingBlock(6);
obj.fallBlock(new Block(1 /* left */, 3 /* right */, 2 /* height */));
│                  │
│  ┌──────┐        │
│  │      │        │
└──└──────┘────────┘
obj.getMaxHeight() -> 2
obj.fallBlock(new Block(3 /* left */, 4 /* right */, 2 /* height */));
│       ┌────┐     │
│       │    │     │
│  ┌────└─┬──┘     │
│  │      │        │
└──└──────┘────────┘
obj.getMaxHeight() -> 4
*/


