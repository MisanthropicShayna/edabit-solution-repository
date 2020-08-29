=begin
Dance for Cash @ https://edabit.com/challenge/kiFisCTSoy2Mfag8e

Your local bank has decided to upgrade its ATM machines by incorporating motion sensor technology.
The machines now interpret a series of consecutive dance moves in place of a PIN number.
Create a function that converts a customer's PIN number to its dance equivalent.
There is one dance move per digit in the PIN number. An array of dance moves is given in the code.

Each dance move will be selected from an array by index based on the current digit's value plus that digit's index value.
If this value is greater than the last index value of the dance array, it should cycle to the beginning of the array.

Valid input will always be a string of four digits. Output will be an array of strings.
If the input is not four valid integers, return the string, "Invalid input."

ELISP Version

(defun dance-for-cash (pin)
  (let ((moves '("Shimmy" "Shake" "Pirouette" "Slide" "Box Step" "Headspin" "Dosado" "Pop" "Lock" "Arabesque")))
    (if (not (and (eq (length pin) 4) (cl-every #'cl-digit-char-p pin))) "Invalid input."
      (cl-loop for index from 0 to (- (length pin) 1) collect
               (elt moves (mod (+ (cl-digit-char-p (aref pin index)) index) (length moves)))))))
=end

$moves = ['Shimmy', 'Shake', 'Pirouette', 'Slide', 'Box Step', 'Headspin', 'Dosado', 'Pop', 'Lock', 'Arabesque']

def dance_convert(pin)
  pin.chars.all? { |char| char =~ /[0-9]/ } && pin.size == 4 ? pin.chars.each_with_index.map { |digit, index| $moves[(digit.to_i + index) % $moves.size] } : 'Invalid input.'
end
