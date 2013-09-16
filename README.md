# About SummerProject2013
SummerProject2013 (also called sp13) is a roguelike very much in development 
yet.

# Dependencies
sp13 uses Simple and Fast Multimedia Library version 2.0, and Microsoft Visual 
Studio or SCons <http://www.scons.org/> for building.

# Installing and running

## GNU/Linux
From the project root do:

```sh
cd summerProject2013
scons  			# I usually add -j<number-of-cpu-cores> on this one
./sp13 			# runs the game
```

## Windows
### SCons
See GNU/Linux, powershell and SCons worked the same way for me 
(thomassigurdsen) when I tried building it on an MS Windows machine.

### Microsoft Visual Studio
It is apparently possible to build this sourcecode with Visual Studio, I 
(thomassigurdsen) haven't tried (I hear there is some fishy business with 
"release mode", but I don't know).
TODO: write up this section.

## Mac
See GNU/Linux, thomassigurdsen would assume it works with bash and SCons just 
as with Linux.

# Licensing and Legalese
## Media
See summerProject/font/licensing.txt, summerProject/img/licensing.txt, and 
summerProject/music/licensing.txt

## Code
SummerProject2013 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SummerProject2013 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SummerProject2013.  If not, see <http://www.gnu.org/licenses/>.
