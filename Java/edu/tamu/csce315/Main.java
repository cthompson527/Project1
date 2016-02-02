package edu.tamu.csce315;


import java.util.ArrayList;
import java.util.Collections;
import org.apache.commons.math3.stat.descriptive.SummaryStatistics;
import org.apache.commons.math3.stat.inference.*;


/**
 * Created by Cory Thompson on 1/20/16.
 * The Main class. This class contains the main function and uses Team and Parser for implementation.
 * This class prints the values to the console
 */
public class Main {
    public static void main(String[] args) {
        Parser p = new Parser("../Input File/315Assignment1.txt");
        SummaryStatistics ssASM = new SummaryStatistics();
        SummaryStatistics ssPSM = new SummaryStatistics();
        ArrayList<Team> teams = p.createTeams();
        Collections.sort(teams);
        for (Team team : teams) {
            System.out.println(team);
            ssASM.addValue(team.getASM());
            ssPSM.addValue(team.getPSM());
        }

        TTest tTest = new TTest();
        double tStatistic;
        tStatistic = tTest.t(ssASM, ssPSM);

        System.out.printf("\n\n%-19s %-11s %-6s\n", "Type", "ASM", "PSM");
        printResult("sample size", ssASM.getN(), ssPSM.getN());
        printResult("mean", ssASM.getMean(), ssPSM.getMean());
        printResult("standard dev", ssASM.getStandardDeviation(), ssPSM.getStandardDeviation());
        printResult("standard error", ssASM.getStandardDeviation()/Math.sqrt(ssASM.getN()), ssASM.getStandardDeviation()/Math.sqrt(ssPSM.getN()));
        printResult("maximum", ssASM.getMax(), ssPSM.getMax());
        printResult("minimum", ssASM.getMin(), ssPSM.getMin());

        System.out.printf("\n%-15s %.6f", "t-Statistic", tStatistic);
        System.out.println();
    }

    /**
     * Prints the values to the console
     * @param type String of the type of statistic computed.
     * @param asm Actual Scoring Margin resulted
     * @param psm Predicted Scoring Margin resulted
     */
    public static void printResult(String type, double asm, double psm) {
        System.out.printf("%-20s", type);
        System.out.printf("%.2f\t", asm);
        System.out.printf("%.2f\n", psm);
    }

}
