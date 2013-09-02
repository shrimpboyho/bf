/**

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

(function () {
    window.Bf = function () {

        this.memory = [];
        var i;
        for (i = 0; i < 600; i++) {
            this.memory.push(00000000);
        }
        this.ptr = 0;
        this.output = "";

    };

    Bf.prototype.parse = function (code) {
        var i; // instruction pointer
        for (i = 0; i < code.length; i++) {
            if (code[i] === '>') this.ptr++;
            if (code[i] === '<') this.ptr--;
            if (code[i] === '+') this.memory[this.ptr] = (parseInt(this.memory[this.ptr], 2) + 1).toString(2);
            if (code[i] === '-') this.memory[this.ptr] = (parseInt(this.memory[this.ptr], 2) - 1).toString(2);
            if (code[i] === '.') this.output += String.fromCharCode(parseInt(this.memory[this.ptr], 2));
            if (code[i] === '[') {
                if (parseInt(this.memory[this.ptr], 2) === 0) {
                    while (code[i] !== ']') {
                        i++;
                    }
                    i++;
                }
            }
            if (code[i] === ']') {
                if (parseInt(this.memory[this.ptr], 2) !== 0) {
                    while (code[i] !== '[') {
                        i--;
                    }
                    i--;
                }
            }
        }

        return this.output;

    };

})();
