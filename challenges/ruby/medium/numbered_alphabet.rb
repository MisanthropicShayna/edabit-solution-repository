=begin
Numbered Alphabet @ https://edabit.com/challenge/EGKhcyaaox6NZL6fh

Create a function that converts a string of letters to their respective number in the alphabet.
=end

def alph_num(string)
  indexes = string.chars.map do |character|
    if character.ord >= 'A'.ord && character.ord <= 'Z'.ord
      character.ord - 'A'.ord
    elsif character.ord >= 'a'.ord && character.ord <= 'z'.ord
      character.ord - 'a'.ord
    else
      character.ord
    end
  end

  indexes.to_s.chars[1..-2].join.gsub(',', '')
end

puts alph_num("H E")
