const merge = (arr, left, middle, right) => {
  let L = arr.slice(left, middle + 1)
  let R = arr.slice(middle + 1, right + 1)
  
  let i = left
  let j = 0
  let k = 0

  while (j < L.length && k < R.length) {
    if (L[j] < R[k]) {
      arr[i] = L[j]
      j++
      i++
      continue
    }

    arr[i] = R[k]
    k++
    i++
  }

  while (j < L.length) {
    arr[i] = L[j]
    j++
    i++
  }
  
  while (k < R.length) {
    arr[i] = R[k]
    k++
    i++
  }
}

const sort = (arr, left, right) => {
  if (left < right) {
    const middle = Math.floor((left + right) / 2)

    sort(arr, left, middle)
    sort(arr, middle + 1, right)

    merge(arr, left, middle, right)
  }
}

const mergesort = (arr) => {
  sort(arr, 0, arr.length - 1)
}

const getTestArray = (int) => {
  let arr = []
  
  for (let i = 0; i < int; i++) {
    arr.push(Math.floor(Math.random() * Math.floor(10)))  
  }

  return arr
}

const main = () => {
  let arr = getTestArray(parseInt(process.argv[2], 10))

  //console.log(arr)
  console.time('mergesort')

  mergesort(arr)
  
  console.timeEnd('mergesort')
  //console.log(arr)
}

main()
