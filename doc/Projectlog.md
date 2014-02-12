Printer
-------

####12.02.2014
This project is currently lacking a name. We thought about "Monaco9 is seven pixels tall", but it turns out we want to use a font thats eight pixels tall, so we could go with "We need a font" as the current project name.


####12.02.2014 17:02

Played around with some fonts. The goal was to find or create a font that would fit within the height of 8 pixels.

The plan is to store the bitmaps for all the symbols in a run-length encoded format, running form top to bottom, left to right (note the order, first vertical, then horizontal). Therefore choosing a font that uses 8 rows and 5 columns allows for storing a symbol using one byte for each column in the bitmap, making the data easy to process. Considering how the device will print the characters, this format is very appropriate.

For a reference on the printing method, look at [txtBOMBER](http://www.behance.net/gallery/txtBOMBER/406136) or [Time Writer](http://oliviervanherpt.nl/time-writer/), the idea for this project is based of those two.

I created a draft for a font based off Monaco. Turns out uppercase letters fit quite nicely within the the 5x8 pixel constraint, even without modifications. Lowercase letters are more problematic. I tried squeezing the all the lowercase letters into the 5x8 format, but the result wasn't too great on some of them.

[Link to the font](./sampleFont0.png)

--jarmo
