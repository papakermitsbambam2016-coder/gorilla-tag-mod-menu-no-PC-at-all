package com.universalvr

import android.app.Activity
import android.os.Bundle
import android.graphics.Color
import android.view.Gravity
import android.view.ViewGroup
import android.widget.Button
import android.widget.FrameLayout
import android.widget.LinearLayout
import android.widget.TextView

class MainActivity : Activity() {

    private lateinit var armValue: TextView

    private var armLength = 1.0


    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)

        showMenu()

    }


    private fun showMenu() {

        val root = FrameLayout(this)

        root.setBackgroundColor(
            Color.rgb(
                12,
                12,
                16
            )
        )


        val panel = LinearLayout(this).apply {

            orientation = LinearLayout.VERTICAL

            setPadding(
                48,
                32,
                48,
                32
            )

            gravity = Gravity.CENTER_HORIZONTAL

        }


        fun createLabel(
            textValue: String,
            size: Float
        ): TextView {

            return TextView(this).apply {

                text = textValue

                textSize = size

                setTextColor(
                    Color.WHITE
                )

                setPadding(
                    0,
                    8,
                    0,
                    8
                )

            }

        }


        val title =
            createLabel(
                "UniversalVR",
                30f
            )

        panel.addView(title)


        val version =
            createLabel(
                "Quest • v0.1.0",
                15f
            )

        panel.addView(version)


        armValue =
            createLabel(
                "Long Arms: 1.00x",
                20f
            )

        panel.addView(armValue)


        val decreaseButton =
            Button(this).apply {

                text = "− Decrease"

                setOnClickListener {

                    changeArms(
                        -0.05
                    )

                }

            }

        panel.addView(
            decreaseButton
        )


        val increaseButton =
            Button(this).apply {

                text = "+ Increase"

                setOnClickListener {

                    changeArms(
                        0.05
                    )

                }

            }

        panel.addView(
            increaseButton
        )


        val resetButton =
            Button(this).apply {

                text = "Reset Arms"

                setOnClickListener {

                    armLength = 1.0

                    updateArmText()

                }

            }

        panel.addView(
            resetButton
        )


        val gameTitle =
            createLabel(
                "\nGame Adapters",
                20f
            )

        panel.addView(
            gameTitle
        )


        val games =
            createLabel(
                """
BONELAB
Gorilla Tag
Scary Baboon
                """.trimIndent(),
                18f
            )

        panel.addView(
            games
        )


        val information =
            createLabel(
                """
UniversalVR APK Core

Game-specific adapters will connect
supported games to UniversalVR.

Long Arms Range:
0.50x - 3.00x
                """.trimIndent(),
                14f
            )

        panel.addView(
            information
        )


        val params =
            FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.WRAP_CONTENT,
                ViewGroup.LayoutParams.WRAP_CONTENT
            ).apply {

                gravity =
                    Gravity.CENTER

            }


        root.addView(
            panel,
            params
        )


        setContentView(
            root
        )

    }


    private fun changeArms(
        amount: Double
    ) {

        armLength += amount


        if (
            armLength < 0.5
        ) {

            armLength = 0.5

        }


        if (
            armLength > 3.0
        ) {

            armLength = 3.0

        }


        updateArmText()

    }


    private fun updateArmText() {

        armValue.text =
            "Long Arms: %.2fx".format(
                armLength
            )

    }

}
