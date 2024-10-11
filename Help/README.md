# X584 Help

This help has been created initially in DOC format so it cannot be opened on 
computers where Microsoft Office has not been installed and some tables and
images have displaced on new versions of Microsoft Office such as 2016.

When I was converting this help from DOC to CHM, I spotted some orthographic
and punctuation errors and ran into problems with illustrations in document
created with pictures and Microsoft Word figures (compound images), and 
formulas in Microsoft Equation 3.0 which can be represented in a 
platform-independent way only as image. I had to create image files from 
formulas and illustrations and put them inside HTML file by hand. I helped
myself by converting DOC into HTML and cleaning it up from redundant tags.

I think that this help will be as helpful as twenty years ago for students
who study the "Computing Systems Architecture" subject until something new
system which has another instruction set architecture as its base will be
created and displace X584.

*Danila A. Kondratenko, IVT-221*

P.S. For future reference. **NEVER EVER CREATE HELP FILES IN FORMATS LIKE
DOC OR DOCX** (only if you want to make difficulties to future 
generations). Nowadays there are multiple markup languages which make 
help file generation in various formats much and much simpler.

## Build instructions

To build X584 help, you will need HTML Help Workshop from Microsoft which
contains HTML Help Compiler inside it. You should run this command in your
command prompt from HTML Help Workshop run directory:

     > hhc X584.hhp
