#coding: utf-8

=begin
Where's Waldo? @ https://edabit.com/challenge/xFttKDaH9uYfsgvD8

Return the coordinates ([row, col]) of the element that differs from the rest.

Example
where_is_waldo([
  ["A", "A", "A"],
  ["A", "A", "A"],
  ["A", "B", "A"]
]) => [3, 2]
=end

def where_is_waldo(rows)
  rowmap = {}

  rows.each_with_index do |row, row_index|
    row.each_with_index do |column, column_index|
      if rowmap.include?(column)
        rowmap[column].push([row_index, column_index])
      else
        rowmap[column] = [[row_index, column_index]]
      end
    end
  end

  _, waldo_locations = rowmap.min_by { |_, v| v.size }

  if waldo_locations.size
    waldo_row, waldo_column = waldo_locations[0]
    return [waldo_row+1, waldo_column+1]
  else
    return nil
  end
end
