public class Solution {

    public static void appendNumberOfChars(StringBuilder sb, int n, char c) {
        while (n-- > 0) {
            sb.append(c);
        }
    }


    public static String justifyRegularLine(String[] words, int maxWidth, int first, int last, int currLen) {
        StringBuilder justifiedLine = new StringBuilder(words[first]);

        if (first == last) {
            appendNumberOfChars(justifiedLine, maxWidth-words[first].length(), ' ');
        }
        else {
            int avgNSpaces = (maxWidth - currLen) / (last-first);
            int nAdditional = (maxWidth - currLen) % (last-first);

            for (int i = first+1; i <= first+nAdditional; i++) {
                appendNumberOfChars(justifiedLine, avgNSpaces+1, ' ');
                justifiedLine.append(words[i]);
            }

            for (int i = first+nAdditional+1; i <= last; i++) {
                appendNumberOfChars(justifiedLine, avgNSpaces, ' ');
                justifiedLine.append(words[i]);
            }
        }

        return justifiedLine.toString();
    }


    public static String justifyLastLine(String[] words, int maxWidth, int first, int last, int currLen) {
        StringBuilder justifiedLine = new StringBuilder(words[first]);

        if (first == last) {
            appendNumberOfChars(justifiedLine, maxWidth-words[first].length(), ' ');
        }
        else {
            for (int i = first+1; i <= last; i++) {
                appendNumberOfChars(justifiedLine, 1, ' ');
                justifiedLine.append(words[i]);
            }
            appendNumberOfChars(justifiedLine, maxWidth-(last-first + currLen), ' ');
        }

        return justifiedLine.toString();
    }

    
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String>  justifiedText = new ArrayList<>();
        int first = 0, currLen = 0;

        for (int i = 0; i < words.length; i++) {
            if (currLen + i-first + words[i].length() <= maxWidth) {
                currLen += words[i].length();
            }
            else {
                justifiedText.add(justifyRegularLine(words, maxWidth, first, i-1, currLen));
                currLen = words[i].length();
                first = i;
            }
        }
        justifiedText.add(justifyLastLine(words, maxWidth, first, words.length-1, currLen));
        return justifiedText;
    }
}
