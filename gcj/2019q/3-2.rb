T = gets.to_i
T.times do |cas|
  n, l = gets.split.map &:to_i
  c = gets.split.map &:to_i

  k = 0
  k += 1 while c[k] == c[k + 1]
  primes = Array.new l
  primes[k + 1] = c[k].gcd c[k + 1]
  # p ggg[primes[k + 1]]

  k.downto 0 do |i|
    primes[i] = c[i] / primes[i + 1]
    # p [i, c[i], ggg[primes[i + 1]], c[i] % primes[k + 1], ggg[primes[i]]]
  end
  (k + 2).upto l - 1 do |i|
    primes[i] = c[i - 1] / primes[i - 1]
    # p [i, c[i - 1], ggg[primes[i - 1]], c[i - 1] % primes[i - 1], ggg[primes[i]]]
  end

  h = primes.sort.uniq.zip(?A..?Z).to_h

  puts "Case ##{cas + 1}: " + primes.map{|q| h[q] }.join
end
