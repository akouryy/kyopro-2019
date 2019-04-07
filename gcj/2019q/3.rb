T = gets.to_i
T.times do |cas|
  n, l = gets.split.map &:to_i
  c = gets.split.map &:to_i

  k = 0
  k += 1 while c[k] == c[k + 1]
  primes = Array.new l + 1
  primes[k + 1] = c[k].gcd c[k + 1]

  k.downto 0 do |i|
    primes[i] = c[i] / primes[i + 1]
  end
  (k + 1).upto l do |i|
    primes[i] = c[i - 1] / primes[i - 1]
  end

  h = primes.sort.uniq.zip(?A..?Z).to_h

  puts "Case ##{cas + 1}: " + primes.map{|q| h[q] }.join
end
