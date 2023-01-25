module.exports = function toReadable (number) {
    let result = '';
    let one_dig_arr = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
    let two_dig_arr = ['ten', 'elven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen','eighteen', 'nineteen'];
    let arr_ty = ['twenty', 'thirty', 'fourty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety'];
    if (number < 10){
        return one_dig_arr[number];
    }else if(number >= 10 && number <= 19){
        return two_dig_arr[number-10];
    }else if(number>= 20 && number < 100){
        if (number%10 === 0){
            let i = 0;
            while(i<=(number/10)){
                i++;
            }
            result = `${result}${arr_ty[i-3]}`;
        }
    }else if(number < 1000){

    }
}
