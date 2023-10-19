import struct

file = open( "/dev/input/by-path/pci-0000:00:15.0-platform-i2c_designware.0-mouse", "rb" );

def getMouseEvent():
  buf = file.read(3);
  print(buf)
  button = buf[0];
  print(button)
  bLeft = button & 0x1;
  bMiddle = ( button & 0x4 ) > 0;
  bRight = ( button & 0x2 ) > 0;
  x,y = struct.unpack( "bb", buf[1:] );
  print ("L:%d, M: %d, R: %d, x: %d, y: %d\n" % (bLeft,bMiddle,bRight, x, y) );
  # return stuffs

while( 1 ):
  getMouseEvent();
file.close();